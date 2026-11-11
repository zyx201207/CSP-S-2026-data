#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
using namespace std;
ll n,p,q,cnt=0;
struct chuan{
	ll a;
	char c;
};
chuan s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;++i){
		cin>>s[i].a;
		cin>>s[i].c;
	}
	p=1;
	q=n;
	while(p<q){
		if(s[p].a>s[q].a){
			if(s[p].c!=s[q].c){
				cnt+=s[q].a;
			}else{
				cnt+=0;
			}
			--q;
			s[p].a-=s[q+1].a;
			continue;
		}
		if(s[p].a<s[q].a){
			if(s[p].c!=s[q].c){
				cnt+=s[p].a;
			}else{
				cnt+=0;
			}
			++p;
			s[q].a-=s[p-1].a;
			continue;
		}
		if(s[p].a==s[q].a){
			if(s[p].c!=s[q].c){
				cnt+=s[p].a;
			}else{
				cnt+=0;
			}
			--q;
			++p;
			continue;
		}
	}
	cout<<cnt;
	return 0;
} 
