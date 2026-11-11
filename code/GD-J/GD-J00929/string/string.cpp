#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct node{
	ll a;
	char c;
}s[200010];
int n;
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(s[l].c==s[r].c){
			if(s[l].a==s[r].a){
				l++;
				r--;
			}else{
				if(s[l].a>s[r].a){
					s[l].a-=s[r].a;
					r--;
				}else{
					s[r].a-=s[l].a;
					l++;
				}
			}
		}else{
			if(s[l].a>s[r].a){
				ans+=s[r].a;
				s[l].a-=s[r].a;
				r--;
			}else{
				ans+=s[l].a;
				s[r].a-=s[l].a;
				l++;
			}
		}
	}cout<<ans;
	return 0;
}
