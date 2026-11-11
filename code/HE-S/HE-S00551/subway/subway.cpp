#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	/*freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);*/
	int h=1;
	for(;h<=5;h++){}
	cout<<h;
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1];
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int a[m+1][d];
	int t[m+1][d];
	int p[m];
	int l[n][n];
	bool ch[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ch[i][j]=false;
		}
	}
	for(int i=1;i<=m;i++)
	{
		p[i]=0;
	}
	int k;
	int s;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>s;
			a[s][p[s]]=i;
			cin>>t[s][p[s]];
			p[s]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<d;j++)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<p[i]-1;j++)
		{
			for(int k=1;k<p[i];k++)
			{
				if(not ch[a[i][j]][a[i][k]])
				{
					l[a[i][j]][a[i][k]]=t[i][j]+t[i][k];
					ch[a[i][j]][a[i][k]]=true;
				}
				else
				{
					l[a[i][j]][a[i][k]]=min(l[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
					l[a[i][k]][a[i][j]]=l[a[i][j]][a[i][k]];
				}
			}
		}
	}
	for(int i=0;i<m-2;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			for(int k=1;k<n;k++)
			{
				for(int ps=0;ps<n;ps++)
				{
					l[i][j]=min(l[i][j],l[i][ps]+l[ps][j]);
					l[j][i]=l[i][j];
				}
			}
		}
	}
	int x,y;
	bool ck;
	for(int i=0;i<q;i++)
	{
		cin>>x>>y;
		ck=false;
		s=0;
		for(int i=0;i<p[x];i++)
		{
			for(;a[y][s]<a[x][i];s++)
			{
				
			}
		}
	}
	return 0;
}
