#include<bits/stdc++.h>
using namespace std;

int to[500005];
int now;
void add(int a,int b)
{
	to[now]=b;
	from[now]=a;
	now++;
	retuen ;
}
int c,n,m,d,q;
int w[500005];
int k;
int a[5005][500005],t[500005][5005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c >>n >>m >>d >>q;
	for(int i=1;i<=m;i++)
	{
		cin >>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >>k;
		for(int j=1;j<=k;j++)
		{
			cin >>a[i][j] >>t[j][i];
			for(int y=1;y<=j;y++)
			add(y,j);
			add(j,y);
		}
	}
	cout <<"ºÃÄÑ..."
	return 0;
} 
