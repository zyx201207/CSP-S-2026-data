#include <bits/stdc++.h>
using namespace std;
int n,m,a[31][200005],g[31],b[200001],k,c[200001],d[31],ans;
bool p[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	d[1]=1;
	for(int i=2;i<=30;i++) d[i]=d[i-1]*2;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		k=1;
		while(b[i]>0)
		{
			if(b[i]%2==0) a[k][i]=0;
			else {a[k][i]=1;g[k]++;}
			b[i]/=2;k++;
		}
	}
	for(int i=30;i>=1;i--)
	{
		if(g[i]>=m)
		{
			ans+=d[i];
			for(int j=1;j<=n;j++) 
			if(a[i][j]<1&&!p[j])
			{
				p[j]=true;
			    for(int k=1;k<=30;k++) if(a[k][j]==1) g[k]--;
			}
		}
	}
	cout<<ans;
	return 0;
}
