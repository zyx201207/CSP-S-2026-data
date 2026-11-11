#include<bits/stdc++.h>
using namespace std;
#define itn int
#define ll long long
int n;
ll m;
int minn=0x3f3f3f3f;
int maxx=-0x3f3f3f3f;
int x[500005];
int ans;
bool check(int md)
{
	ll s=0;
	for(int i=1;i<=n;i++)
	{
		if(s>m)
			return 0;
		s=s+abs(md-x[i]);
	}
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x[i],minn=min(minn,x[i]),maxx=max(maxx,x[i]);
	int l=minn,r=maxx,lal,lar,tim=1;
	int mid;
	while(l<r)
	{
		if(lal==l && lar==r)
			break;
		if(tim%100==0)
			lal=l,lar=r;
		mid=(l+r)>>1;
		// printf("%d %d\n",l,r);
		if(check(mid))
			l=mid;
		else
			r=mid;
		tim++;
	}
	maxx=-0x3f3f3f3f;
	mid=(l+r)>>1;
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		int sum=0;
		for(int j=i;j<=n;j++)
		{
			sum=sum+abs(mid-x[j]);
			if(sum>m)
				break;
			ans++;
		}
		maxx=max(maxx,ans);
		// printf("%d %d %d\n",i,ans,sum);
	}
	cout<<maxx;

	return 0;
}