#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int c=0;
		cin>>c;
		v.push_back(c);
	}
	int vis[500005],vis1[500005];
	int ans[500005];
	for(int i=0;i<n;i++)
	{
		vector<int> v1;
		for(int k=0;k<n;k++) v1[k]=v[k];
		for(int j=i;j<n;j++)
		{
			if(vis[v1[j]]!=0)
			{
				v1.erase(v1.begin()+vis[v1[j]],v1.begin()+j);
				vis[v1[j]]=0;
			}
			else 
			{
				vis[v1[j]]=j;
			}
		}
		for(int i=0;i<v1.size();i++)
		{
			if(vis1[v1[i]]==0)
			{
				ans[v1[i]]++;
				vis1[v1[i]]=1;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
