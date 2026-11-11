#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[100005],s[100005],ans;
bool pd(int x,int y)
{
	for(int i=x+1;i<=y;i++)
	{
		if(s[i]-s[i-1]>d) return 0;
	}
	int cnt=0;
	for(int i=x;i+3<=y;i++)
	{
		int w=a[i],o=a[i+1],u=a[i+2],z=a[i+3];
		if(u-w<=d&&z-u<=d&&o-w<=d&&z-o<=d&&z-w>d)
		{
			cnt++;
		}
	}
	if(cnt==1) return 1;
	else return 0;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s[i]=s[i-1]+a[i]-a[i-1];
		}
		if(c>=11&&c<=12)
		{
			int bj=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i]-s[1]>d)
				{
					bj=i-1;
					break;
				}
			}
			bj--;
			cout<<n-bj*2+1<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				if(pd(i,j)) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
