#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int T,t,n,d,a[N],b[N],c[N],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T>>t;
	while(t--)
	{
		cin>>n>>d;
		memset(b,0x3f,sizeof(b));
		b[0]=b[1]=0;
		ans=0;
		memset(c,0,sizeof(c));
		for(int i=1; i<=n; i++)
		{
			cin>>a[i];
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				if(a[j]-a[i]>d)
				{
					break;
				}
				if(b[j]==b[i+1])
				{
					c[j]++;
				}
				else if(b[j]>b[i]+1)
				{
					b[j]=b[i]+1;
					c[j]=1;
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			if(c[i]==2)
			{
				ans++;
			}
		}
		cout<<ans-1<<"\n";
	}
	return 0;
}
