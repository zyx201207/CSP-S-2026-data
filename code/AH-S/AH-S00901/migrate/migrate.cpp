#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],f[2000005],t1[2000005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		x[0]=LONG_MIN;
		for(int j=1;j<=n;j++)
		{
			f[j]=1;
			for(int i=1;i<=n;i++)
				t1[i]=1;
			for(int i=j+1;i<=n;i++)
			{
				f[i]=LONG_LONG_MAX;
				int e=i;
				while(--e)
				{
					if(x[i]-x[e]>d||e<j)
					break;
					if(f[i]==f[e]+1)
					t1[i]+=t1[e];
					if(f[i]>f[e]+1)
					{
						t1[i]=t1[e];
						f[i]=f[e]+1;
					}
				}
				if(t1[i]==2)
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}
