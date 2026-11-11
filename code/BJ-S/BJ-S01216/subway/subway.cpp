#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[100001],k,a[10001],t[10001],ans=0,x,y,xmax=-1;
vector<int>ljb[100001];
vector<bool>vist[100001];
vector<bool>hc[100001];
void dfs(int x,int y)
{
	if(x==y)
		xmax=max(ans,xmax);
	for(int i=0;i<k;i++)
	{
		if(vist[x][i]==0)
		{
			if(hc[x][i]!=hc[x][i+1])
			{
				
				ans+=t[ljb[x][i]];
			}
			
			dfs(x,i);
		}
		else
		{
			vist[x][y]=0;
			ans-=t[ljb[x][i]];
		}
			
		
			
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>a[j]>>t[j];
		}
		for(int f=0;f<k;f++)
		{
			if(f>=1)
			{
				ljb[f].push_back(a[f-1]);
			}
			ljb[f].push_back(a[f+1]);
			hc[f].push_back(i);
			ljb[f].push_back(0);
		}
	}
	int qwe=0;
	for(int i=0;i<q;i++)
	{
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		qwe+=w[x];
		qwe+=w[y];
	//	dfs(x,y);
	//	cout<<xmax;
		cout<<qwe;
		ans=0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
