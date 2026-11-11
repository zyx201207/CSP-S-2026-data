#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q,x,y;
vector <int> w;
vector <int> a[505];
vector <int> t[505];
vector <int> k;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
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
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			if(k[i]-w[i-1]+t[i][a[i][j]]%21==0)
			{
				cout<<w[i] + t[i][j] + (t[i][j+1] + t[i+1][j+1]) + t[i+1][i+2] + w[i+2]<<endl<< w[i] + t[i][j] + t[i][j+1] + w[i+1];
			}
			else
			{
				cout<<w[i] + t[j][j] + (t[i][i+1] + t[i+1][j+1]) + t[j+1][i+2] + w[i+2]<<endl<< w[j] + t[i][j] + t[i][j+1] + w[i+1];
			}
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
