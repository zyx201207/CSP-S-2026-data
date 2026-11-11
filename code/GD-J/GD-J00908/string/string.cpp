#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,a[N],sz=1,ans,sum,col,d;
char c;
map<ll,ll>s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>d;
		cin>>c;
		col=c-'a'+1;
		s[sz]=col;
		sz+=d;
		sum+=d;
	}
	sz--;
	for(ll i=2;i<=sz;i++) if(!s[i]) s[i]=s[i-1];
	ll t=(sz>>1);
	for(ll i=1;i<=t;i++) if(s[i]!=s[sz-i+1]) ans++;
	cout<<ans;
	return 0;
}
