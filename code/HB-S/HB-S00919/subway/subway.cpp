#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,T;
int w[555555];
int k[555];
int a[555][22],t[555][22];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
	cin>>c>>n>>m>>d>>q;
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
			T=t[i][j];
		}
	}
	int x,y;
	while(c--)
	{
		cin>>x>>y;
		for(int i=1;i<=T;i++)
		{
			
		}
		
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
