#include <bits/stdc++.h>
using namespace std;
long long x[2000005];
int f[2000005];
long long s[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		s[0]=s[1]=0;
		for(int i=2;i<=n;i++)
		{
			s[i]=s[i-1]+x[i]-x[i-1];
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			long long j=i+3;
			long long k=s[j]-s[i];
			k=k/d;
			if(k==1 && k*d!=s[j]-s[i])
			{
				ans++;
			}
			if(k/d>=2)
			{
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
