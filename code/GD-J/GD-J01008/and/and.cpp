#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define SIZE 200005
int n,m;
int a[SIZE],cnt[35];
bool is[SIZE][35];
vector<int> ve,ce;
signed main()
{
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m ;
	
	for (int i=1;i<=n;++i)
		cin >> a[i] ;
		
	sort (a+1,a+n+1,greater<int>());
	
	for (int i=1;i<=n;++i)
	{
		for (int o=0;(1<<o)<=a[i];++o)
		{
			int k=(1<<o)&a[i];
			if (k)
			{
				is[i][o]=true;		
				cnt[o]++;		
			}
		}
	}
	
	int ans=0,times=0;
	bool us=0;
	for (int i=35;i>=0;--i)
	{
		if (cnt[i]<m)
			continue;
			
		if (!us)
		{
			for (int o=1;o<=n;++o)
			{
				if (is[o][i])
					ve.push_back(o);
			}
			
			ans=(1<<i);
			us=true;
			continue;
		}
		
		int cnt1=0;
		for (int v:ve)
		{
			if (is[v][i])
				cnt1++;
		}
		
		if (cnt1>=m)
		{
			ce={};
			for (int v:ve)
				if (is[v][i])
					ce.push_back(v);
			
			ve=ce;
			ans+=(1<<i);
		}
	}
	
	cout << ans ;
	return 0;
}
