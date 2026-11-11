#include<iostream>
#include<algorithm>
using namespace std;
long long int n,m,a[500005],sum[500005],maxx=-1,c[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int s=a[j]-a[i];
			sum[j]+=s;
		}
	}
	for(int i=1;i<=n;i++)
		if(sum[i]<=m&&i>=maxx)maxx=i;
	cout<<maxx<<endl;
}
