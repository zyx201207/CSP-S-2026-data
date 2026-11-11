#include <bits/stdc++.h>
#define ll long long
const ll N=5*1e5;
using namespace std;
ll c,T,n,d,x[N],cnt1,cnt2,r,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>x[i];
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				cnt1=cnt2=0;
				r=i;
				for(ll k=r;k<=j;k++)
				{
					if(x[k]-x[r]>d)r=k-1,cnt1++;
				}
				r=j;
				for(ll k=j;k>=r;k--)
				{
					if(x[r]-x[k]>d)r=k+1,cnt2++;
				}
				if(cnt1==cnt2)ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
