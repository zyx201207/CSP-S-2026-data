#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1000005;
ll c,t,n,d,x[INF],ans,ww;
int search(int beginn,int ending,int qqq)
{
	if(beginn==ending && qqq==ww)return 1;
	int k=0ll;
	for(ll i=beginn+1ll;i<=ending;i++)
	{
		if(x[i]-x[beginn]<=d)
		{
			k+=search(i,ending,qqq+1);
		}
	}
	return k;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.ans","w",stdout);
	cin>>c>>t;
	for(ll i=1ll;i<=t;i++)
	{
		cin>>n>>d;
		ans=0;
		for(ll j=1ll;j<=n;j++)
		{
			cin>>x[j];
		}
		for(ll j=1ll;j<=n-1ll;j++)
		{
			for(ll k=j+1ll;k<=n;k++)
			{
				int a=j;ww=1ll;
				for(ll l=j;l<=k;l++)
				{
					if(x[l]-x[a]>d)
					{
						a=l-1ll;
						ww++;
					}
				}
				if(search(j,k,0)==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}