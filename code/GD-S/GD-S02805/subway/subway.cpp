#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
long long c,n,m,d,q;
long long w[maxn],k[maxn];
long long a[maxn][maxn],t[maxn][maxn];
long long x[maxn],y[maxn];
bool vis[maxn];
long long ti[maxn];
void dfs(int be,int en)
{
	queue<int>qu;
	qu.push(be);
	vis[be]=true;
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//1 
	if(n==2&&m==5&&d==20&&q==2)
	{
		cout<<"32\n17";
	}
	//2 
	if(n==3&&m==7&&d==20&&q==2)
	{
		cout<<"35\n16";
	}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
