#include<bits/stdc++.h>//172.16.12.5
using namespace std;

#ifdef LOCAL
#define debug(x) cerr<<#x<<" = "<<(x)<<'\n';
#else
#define debug(x)
#endif
#define ll long long
#define vct vector
#define pb push_back
#define PII pair<int,int>
#define int long long

#ifdef LOCAL
bool ____ST;
#endif
int n,m,a[500010],e[500010],ans;
#ifdef LOCAL
bool ____ED;
#endif

bool chk(int l,int r)
{
	return a[r]*(r-l+1)-(e[r]-e[l-1])<=m;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	cerr<<double(&____ED-&____ST)/(1024*1024)<<"Mib\n";
	double ____st=clock();
#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		e[i]=e[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=l+r>>1;
			if(!chk(mid,i))
			{
				l=mid+1;
			}
			else
			{
				r=mid;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
#ifdef LOCAL
	double ____ed=clock();
	cerr<<'\n'<<(____ed-____st)/CLOCKS_PER_SEC*1000<<"ms\n";
#endif
	return 0;
}
