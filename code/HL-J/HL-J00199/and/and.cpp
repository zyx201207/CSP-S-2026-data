#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],f[200005][205],tmp=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		tmp=max(tmp,a[i]);
		f[i][1]=tmp;
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=i;j<=n;j++)
		{
			f[j][i]=max(f[j-1][i],f[j-1][i-1]&a[j]);
			//cout<<f[j][i]<<' ';
		}
		//cout<<endl;
	}
	cout<<f[n][m];
	return 0;
}
/*
5 3
31 3 1 15 7
*/
