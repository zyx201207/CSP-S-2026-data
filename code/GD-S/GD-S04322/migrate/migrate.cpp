#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

const int N=2e6,E=(N<<1),inf=2e9;

int c,T;
int n; long long d;
long long a[N+1];

int f[N+1],cnt[N+1];
int ans;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		
		if(c<=25)
		{
			ans=0;
			for(int st=1;st<=n;st++)
			{
				for(int i=1;i<=n;i++) f[i]=inf,cnt[i]=1;
				
				f[st]=0;
				for(int i=1;i<=n;i++)
				{
					for(int k=1;k<=n;k++)
					{
						if(k==i) continue;
						if(llabs(a[k]-a[i])>d) continue;
						
						if(f[k]>f[i]+1) f[k]=f[i]+1,cnt[k]=1;
						else if(f[k]==f[i]+1) cnt[k]++;
					}
				}
				
				for(int i=1;i<=n;i++) ans+=(cnt[i]==2);
			}
			
			cout<<ans<<'\n';
		}
	}
	
	return 0;
}

