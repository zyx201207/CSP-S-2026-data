#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=310;
const int N=2e6+10;
const int inf=0x3f3f3f3f3f3f3f3f;

int c, T;
int n, d;
int a[N];
int f[N], dis[N];


void solve_1()
{
	int ans=0;
	for(int st=1; st<=n; st++)
	{
		for(int i=st; i<=n; i++) f[i]=0, dis[i]=inf;
		f[st]=1, dis[st]=0;
		for(int i=st; i<=n; i++)
		{
			if(f[i]>=3) f[i]=3;
			for(int j=i; j<=n && a[j]-a[i]<=d; j++)
			{
				if(dis[j]>dis[i]+1) dis[j]=dis[i]+1, f[j]=f[i];
				else if(dis[j]==dis[i]+1) f[j]+=f[i];
			}
		}
		for(int i=st; i<=n; i++) if(f[i]==2) ans++;
	}
	cout<<ans<<endl;
}




signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	scanf("%lld %lld", &c, &T);
	while(T--)
	{
		scanf("%lld %lld", &n, &d);
		for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
	
		if(n<=5000) solve_1();
	
	}
	
	
	return 0;
}
