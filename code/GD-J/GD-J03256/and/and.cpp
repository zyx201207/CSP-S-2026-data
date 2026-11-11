#include<bits/stdc++.h>
using namespace std;
const int N=2005;
long long n,m,a[N],ans,f[N][N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][1]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i][j],max(f[i-1][j],f[i-1][j-1]&a[i]));
		}
	}
	cout<<f[n][m];
	return 0;
}
