#include<bits/stdc++.h>
using namespace std;
#define N 50050
int w[N],a[550][N],t[550][N],mmap[550][N];
int c,n,m,d,q,x,y,sum;

int dfs(int l,int r)
{
	if(mmap[l][r]==y)
	{
		cout<<w[x]+w[y]<<endl;
		return;
	} 
	dfs(l,r+1);
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			if(j>1) mmap[i][a[i][j-1]]=a[i][j];
		}
		
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		dfs(1,1);
	}
	return 0;
}



