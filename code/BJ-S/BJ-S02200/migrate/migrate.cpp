#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,x[5005],s[5005][5005],d;
ll check(ll z,ll f,ll k,ll e)
{
	if(z==f)
	{
		if(k==e) return 1;
		return 0;
	}
	ll ret=0;
	for(ll i=z+1;i<=f;i++)
	{
		if(x[i]-x[z]<=d&&k+1<=e) ret+=check(i,f,k+1,e);
	}
	return ret;
}		
int main()
{
	ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ll n,ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>x[i];
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++) s[i][j]=-1;
		}
		for(ll i=1;i<=n;i++)
		{
			s[i][i]=0;
			for(ll j=i+1,t=i;j<=n;j++)
			{
				if(x[j]-x[j-1]>d) break;
				while(x[j]-x[t]>d) t++;
				s[i][j]=s[i][t]+1;
			}
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+3;j<=n;j++)
			{
				if(s[i][j]==-1) break;
				if(check(i,j,0,s[i][j])==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}