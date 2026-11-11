#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
int test_id,t,n;
i64 d;
i64 x[2000007];
int l[2000007];
int r[2000007];
int f[2000007];
int g[2000007];
i64 ans;
int cnt[2000007];
vector<int> nd[2000007];
signed main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>test_id>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1,j=1;i<=n;i++)
		{
			while(x[i]-x[j]>d)
				j++;
			l[i] = j;
		}
		for(int i=n,j=n;i>=1;i--)
		{
			while(x[j]-x[i]>d)
				j--;
			r[i] = j;
		}
		for(int i=1;i<=n;i++)
			cnt[i] = 0;
		for(int i=1,j=0;i<=n;i++)
		{
			cnt[r[i]]++;
			while(j<l[i])
			{
				j++;
				cnt[r[j]]--;
			}
			f[i] = 1 + cnt[i];
			if(l[i]!=i&&r[l[i]]==i)
				f[i] += f[l[i]];
		}
		for(int i=1;i<=n;i++)
			cnt[i] = 0;
		for(int i=n,j=n+1;i>=1;i--)
		{
			cnt[l[i]]++;
			while(j>r[i])
			{
				j--;
				cnt[l[j]]--;
			}
			g[i] = 1 + cnt[i];
			if(r[i]!=i&&l[r[i]]==i)
				g[i] += g[r[i]];
		}
//		for(int i=1;i<=n;i++)
//			cerr<<l[i]<<' '<<r[i]<<' '<<f[i]<<' '<<g[i]<<'\n';
		ans = 0;
		for(int i=1;i<=n;i++)
		{
			nd[i].clear();
			cnt[i] = 0;
		}
		for(int i=1;i<=n;i++)
			nd[l[l[i]]].emplace_back(i);
		for(int i=2;i<=n;i++)
			cnt[l[i]]++;
		for(int i=1;i<=n;i++)
		{
			if(i+1<=n)
				cnt[l[i+1]]--;
			ans += cnt[r[i]-1];
			if(r[r[i]]>=i+2&&r[i]-l[r[r[i]]]==1)	
				ans += g[r[r[i]]] - 1;
			for(auto j:nd[i])
//			{
				if(j>=i+2&&r[i]-l[j]==1)
					ans += (i64)(f[i] - 1) * (r[r[i]] == j ? g[j] : 1);
//				cerr<<i<<' '<<j<<'\n'; 
//			}
		}
//		for(int i=1;i<=n;i++)
//			for(int j=i+2;j<=n;j++)
//				if(r[i]-l[j]==1)
//				{
//					ans += (i64)(l[l[j]] == i ? f[i] : 1) * (r[r[i]] == j ? g[j] : 1);
////					cerr<<i<<' '<<j<<' '<<(i64)(l[l[j]] == i ? f[i] : 1) * (r[r[i]] == j ? g[j] : 1)<<'\n';
//				}
		cout<<ans<<'\n';
	}
}
