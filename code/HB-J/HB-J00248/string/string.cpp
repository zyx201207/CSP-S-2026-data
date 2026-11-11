#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
struct node{
	ll a;
	char c;
}t[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].a>>t[i].c;
	}
	ll l=1,r=n,ans=0;
	while(l<r){
		if(t[l].c!=t[r].c){
			if(t[r].a<t[l].a){
				ans+=t[r].a;
				t[l].a-=t[r].a;
				t[r].a=0;
				r--;
			}
			else if(t[r].a>t[l].a){
				ans+=t[l].a;
				t[r].a-=t[l].a;
				t[l].a=0;
				l++;
			}
			else{
				ans+=t[l].a;
				t[r].a=0;
				t[l].a=0;
				l++;
				r--;
			}
		}
		else{
			if(t[l].a<t[r].a){
				t[r].a-=t[l].a;
				t[l].a=0;
				l++;
			}
			else if(t[l].a>t[r].a){
				t[l].a-=t[r].a;
				t[r].a=0;
				r--;
			}
			else{
				t[r].a=0;
				t[l].a=0;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
