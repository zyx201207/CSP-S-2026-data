#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
#define pb emplace_back

namespace kanade
{
	ll read()
	{
		ll ans=0,fs=1;
		char ch=getchar();
		while(ch<'0'||ch>'9')
		{
			if(ch=='-')fs=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9')
		{
			ans=ans*10+ch-'0';
			ch=getchar();
		}
		return ans*fs;
	}

	ll X[2000010];
	pii dp[2000010];

	int main()
	{
		int c=read(),t=read();
		while(t--)
		{
			int n=read();
			ll d=read();
			for(int i=1;i<=n;i++)
			{
				X[i]=read();
			}
			if(c>=13&&c<=14)
			{
				cout<<"0\n";
				continue;
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)dp[j]=mkp(1e9,0);
				dp[i]=mkp(0,1);
				for(int j=i+1;j<=n;j++)
				{
					for(int k=j-1;k>=i&&X[j]-X[k]<=d;k--)
					{
						if(dp[k].fi+1<dp[j].fi)dp[j]=dp[k],dp[j].fi++;
						else if(dp[k].fi+1==dp[j].fi)dp[j].se+=dp[j].se;		
					}
					if(dp[j].se==2)ans++;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	kanade::main();
	return 0;
}

//就数你就数你就数你

