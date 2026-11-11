#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,m,a[N],f[N][N],ans;
bool fa()
{
	for(int i=1;i<=n;i++)
	{
		bool pd=false;
		for(int k=1;k<=20;k++)
			if(a[i]==pow(2,k)-1)
				pd=true;
		if(pd==false) return false;
	}
	return true;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
		cout<<ans<<endl;
		return 0;
	}
	if(fa())
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
		f[i][1]=a[i];
	for(int j=2;j<=m;j++)
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				f[k][j]=max(f[k][j],f[i][j-1]&a[k]);
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i][m]);
	cout<<ans<<endl;
	return 0;
}
