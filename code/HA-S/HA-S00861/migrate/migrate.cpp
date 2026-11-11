#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[100005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(long long i=1;i<=t;i++)
	{
		long long ans=0;
		cin >> n >> d;
		for(long long j=1;j<=n;j++)
		{
			cin >> a[j];
			if(a[j]>a[j-1]+d+1)
			{
				a[j]=0;
			}
			if(a[j]<0) a[j]=a[j]-a[j]-a[j];
			if(a[j]!=0&&(a[j]-2==2||a[j+1]-2==2)) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}

