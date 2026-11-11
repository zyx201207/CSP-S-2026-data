#include<iostream>
#include<cstdio>
using namespace std;
long long f[2000005];
long long d;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>f[i]; 
		}
		for(int i=1;i<n;i++)
			for(int j=i+2;j<=n;j++)
			{
				if(f[j]-f[i]>d)
				{
					if(j-i>2)
					{
						if((f[j]-f[i+1]<=d&&f[j-1]-f[i]>d)||(f[j]-f[i+1]>d&&f[j-1]-f[i]<=d))ans++;
					}
					else ans++;
				}
			}
		cout<<ans<<'\n';
	}
	return 0;
}
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6



