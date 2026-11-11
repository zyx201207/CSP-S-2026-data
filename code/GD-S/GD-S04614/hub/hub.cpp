#include<bits/stdc++.h>
using namespace std;
vector<int> a[1000060];
int fa[1000050];
int fa1[1000050];
int find(int x)
{
	if(x==fa[x])
	return x;
	return find(fa[x]);
}
int main()
{
	int c,t;
	cin>>c>>t;
	for(int w=0;w<t;w++)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			a[i].clear();
			fa[i]=i; 
		}
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}for(int z=1;z<=n;z++)
		{
			fa1[z]=fa[z]; 
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				
				for(int z=1;z<=n;z++)
				{
					fa[z]=fa1[z]; 
				}
			}
		}
	}
 } 
