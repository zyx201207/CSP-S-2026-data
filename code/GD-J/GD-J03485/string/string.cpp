#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll maxn=2e5+10;
ll n,ans,a,all;
char b,t,p;
struct sb{
	char ch;
	ll l;
}s[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a>>b;
		s[i].l=a;
		s[i].ch=b;
		all+=a;	
	}
	ll i=0,j=n-1;
	while(i<j){
		if(s[i].ch!=s[j].ch) ans+=min(s[i].l,s[j].l);	
		if(s[i].l>s[j].l){
			s[i].l-=s[j].l;
			s[j].l=0;
		}
		else{
			s[j].l-=s[i].l;
			s[i].l=0;
		}
		if(!s[i].l) i++;
		if(!s[j].l) j--;
	}
	cout<<ans;
	return 0;
}

