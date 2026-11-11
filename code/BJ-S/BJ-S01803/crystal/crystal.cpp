#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],n,m,l,ans,sz,cnt[N],sum,anss,b[N];
map<int,int> mp;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	sz=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=sz;i++)mp[b[i]]=i;
	for(int i=1;i<=n;i++)cnt[mp[a[i]]]++;
	for(int i=n;i;i--)
	{
		if(i==n||a[i]!=a[i+1])
		{
			if(i!=n)
			{
				anss-=cnt[mp[a[i+1]]];
				sum-=anss*(a[i+1]-a[i]);
			}
			else l=n;
			while(l>0)
			{
				if(sum+a[i]-a[l]<=m)
				{
					sum+=a[i]-a[l],anss++;
					l--;
				}
				else break;
			}
			ans=max(ans,anss);
		}
	}
	cout<<ans;
	return 0;
}
