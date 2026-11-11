#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
struct node{
	int a;
	char c;
}s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll ans=0;	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		if(s[l].a>s[r].a){
			if(s[l].c==s[r].c){
				s[l].a-=s[r].a;
				r--;
			}else{
				ans+=s[r].a;
				s[l].a-=s[r].a;
				r--;
			}
		}else if(s[l].a<s[r].a){
			if(s[l].c==s[r].c){
				s[r].a-=s[l].a;
				l++;
			}else{
				ans+=s[l].a;
				s[r].a-=s[l].a;
				l++;
			}
		}else{
			if(s[l].c==s[r].c){
				l++;
				r--;
			}else{
				ans+=s[r].a;
				l++;
				r--;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

