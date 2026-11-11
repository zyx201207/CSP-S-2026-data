#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int a[maxn];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,flag=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1&&a[i]<a[i-1])
		{
			flag=0;
		}
	}
	if(flag)
	{
		int idx=1;
		for(int i=1;i<=m;i++)
			if(a[idx]==i)idx++,cout<<n<<" ";
			else cout<<0<<" ";
		return 0;
	}
	vector<int>ans(m+5,0);
	for(int i=1;i<=n;i++)
	{
		vector<int>aa;
		vector<int>idx(n+5,0);
		int ii=1;
		aa.push_back(0);
		for(int j=i;j<=n;j++)
		{
			if(idx[a[j]]!=0)
			{
				while(ii>=1&&ii!=idx[a[j]])
				{
					ii--;
					aa.pop_back();
				}
				aa.push_back(a[j]);
				idx[a[j]]=ii;
				ii++;
			}
			else
			{
				aa.push_back(a[j]);
				idx[a[j]]=ii;
				ii++;
			}
		
		}
		for(int p=1;p<aa.size();p++)
			ans[aa[p]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
