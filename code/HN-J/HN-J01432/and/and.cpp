#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=200100;
const int Log=31;
int n,m;
int a[maxn];
vector<int>f[Log];
vector<int>temp;
bool cmp(int x,int y){return x>y;}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int k=Log-1;k>=0;k--)f[k].push_back(-1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int k=Log-1;k>=0;k--)
		{
			if(a[i]&(1ULL<<k))f[k].push_back(a[i]);
		}
	}
	int ans=0;
	for(int k=Log-1;k>=0;k--)
	{
		if(f[k].size()-1==m)
		{
			ans=f[k][1];
			for(int i=2;i<f[k].size();i++)
			{
				ans&=f[k][i];
			}
			cout<<ans;
			return 0;
		}
		if(f[k].size()-1>m)
		{
			ans+=(1ULL<<k);
			for(int j=k-1;j>=0;j--)
			{
				f[j].clear();
				f[j].push_back(-1);
			}
			for(int i=1;i<f[k].size();i++)
			{
				for(int j=k-1;j>=0;j--)
				{
					if(f[k][i]&(1ULL<<j))f[j].push_back(f[k][i]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
