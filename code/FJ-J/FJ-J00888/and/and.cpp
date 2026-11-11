#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[200007];
bool flag[37];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=30;k>=0;k--)
	{
		vector<int>v;
		for(int i=1;i<=n;i++)
		{
			if((a[i]>>k)&1) v.push_back(a[i]);
		}
		if(v.size()<m)
		{
			flag[k]=0;
		}
		else
		{
			flag[k]=1;
			for(int i=0;i<v.size();i++)
			{
				a[i+1]=v[i];
			}
			n=v.size();
		}
	}
	int ans=0;
	for(int i=0;i<=30;i++)
	{
		if(flag[i]) ans+=(1<<i);
	}
	cout<<ans;
	return 0;
}

