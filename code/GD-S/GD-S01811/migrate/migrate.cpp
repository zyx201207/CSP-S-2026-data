#include<bits/stdc++.h>
using namespace std;
int n,c,t;
long long a[2000002],d,ans;
void yali(int s)
{
	int u=lower_bound(a+s,a+n+1,d)-a;
	if(a[u]!=d)u--;
	if(u-s+1==2)ans++;
	else return ;
	for(int i=s+2;i<=n-2;i++)
	{
		if(a[i+1]-d<=a[i]&&a[i+2]-d>a[i])ans++;
		else return ;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			if(i!=1)
			for(int j=i;j<=n;j++)a[j]=a[j]-a[j-1]+a[j-2];
			yali(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
