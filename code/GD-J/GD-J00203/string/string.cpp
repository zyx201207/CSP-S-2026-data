#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
typedef long long ll;
ll n,ans,tot;
ll s[N];
char ch[N];
string str;
int main() {
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n; i++) {
		int ns;
		char nch;
		cin>>ns;
		cin>>nch;
		if(nch==ch[tot])s[tot]+=ns;
		else {
			tot++;
			ch[tot]=nch;
			s[tot]=ns;
		}
	}
	ll l,r;
	l=1,r=tot;
	//cout<<l<<" "<<r;
	while(l<r) {
		char a,b;
		a=ch[l],b=ch[r];
		ll w=min(s[l],s[r]);
		if(a==b){
			s[l]-=w;
			s[r]-=w;
		}
		else{
			ans+=w;
			s[l]-=w;
			s[r]-=w;
		} 
		while(l<r&&s[l]==0)l++;
		while(r>l&&s[r]==0)r--;
	}
	cout<<ans;
	return 0;
}
