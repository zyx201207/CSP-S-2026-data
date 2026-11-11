#include<bits/stdc++.h>
using namespace std;
long long n,m,c,d,q,k,x,y,xx,yy,sum;
//struct node{
//	int id;
//	int t;
//};
//vector <node> v[500005];
long long a[500005];
void dfs(long long h,long long suma,int luxian)
{
	if (h > yy)
	{
		return ;
	}
	if (h == yy)
	{
		sum = min(sum,suma);
		return ;
	}
	for (int i=1;i<=k;i++)
	{
		suma = suma + ft[i][h];
		luxian = i;
		dfs(fv,long long suma,int luxian)
	}
}
int main()
{
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++)
    {
    	cin >> a[i];  //从地铁口到站台  **一般起始点加一下就行了 
	}
	for (int j=1;j<=n;j++)
	{
		cin >> k;  //线路 i 会经过 k 个站台
		for (int i=1;i<=k;i++)
		{
			cin >> b[i] >> c[i];
		}
		b[0] = 0;
		for (int i=1;i<=k;i++)
		{
			fv[j][i] = b[i-1];  //f[k][i]  路线k经过的第 i 站台是从b[i-1]过来的  
			ft[j][i] = c[i];   //ft[k][i]  路线k第 i 站台所用时间是c[i] 
		}
	}
	for (int i=1;i<=q;i++)
	{
		cin >> xx >> yy;
		dfs(xx);
	}
    return 0;
}

