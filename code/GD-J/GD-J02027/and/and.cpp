#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[200005];
ll o[35],p[35];
bool check(ll x)
{
	memset(o,0,sizeof(o));
	ll op=0;
	ll xx=x;
	while(xx>0)
	{
		o[++op]=xx%2;
		xx=xx/2;
	}
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		ll k=a[i],cnt=0;
		bool fl=0;
		while(k>0)
		{
			p[++cnt]=k%2;
			k=k/2;
		}	
		ll opt=op;
		if(cnt<op)fl=1;
		else
		{
			while(opt>0&&cnt>0)
			{
				if(o[opt]==1&&p[cnt]==0)
				{
					fl=1;
					break;
				}
				opt--,cnt--;
			}
		}
		if(fl==0)sum++;
	}
	if(sum>=m)return 1;
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll maxx=0;
	for(int i=1;i<=n;i++)cin>>a[i],maxx=max(maxx,a[i]);
	ll l=1,r=maxx,ret=0;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid))ret=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ret<<" ";
	return 0;
}
