#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],f[2][200001],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		f[1][i]=a[i];
	}
	for(long long i=2;i<=m;i++)
	{
		for(int j=i;j<=n;j++)
		{
			//now:i%2 last:(i+1)/2
			for(int k=i-1;k<j;k++)
			{
				f[i%2][j]=max(f[i%2][j],f[(i+1)%2][k]&a[j]);
			}
			if(i==m) ans=max(ans,f[i%2][j]);
		}
	}
	cout<<ans;
	return 0;
}
