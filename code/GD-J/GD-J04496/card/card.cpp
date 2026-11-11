#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
vector<int>r[N];
int n,m,p[N],t[N],a[N],ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[p[a[i]]]=i;
		p[a[i]]=i;
	}
	r[n+1].clear();
	for(int i=n;i>=1;i--)
	{
		if(t[i]==0)
		{
			r[i]=r[i+1];
			r[i].push_back(a[i]);
		}
		else
		{
			r[i]=r[t[i]];
		}
		for(int j=0;j<r[i].size();j++)
		{
			ans[r[i][j]]++;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<r[i].size();j++)
//		{
//			cout<<r[i][j]<<endl;
//		}
//	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
