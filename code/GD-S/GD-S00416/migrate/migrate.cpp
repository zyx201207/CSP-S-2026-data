#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const ll M=2e6+5,N=505;
int c,T,n;
ll d,x[M];
ll f[N][N],cnt[N][N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		memset(f,0x7f,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			for(int j=i-1;j>=1;j--)
			{
				if(x[i]-x[j]<=d) f[j][i]=1,cnt[j][i]=1;
				else break;
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				if(f[i][k]==f[0][0]) continue;
				for(int j=1;j<=n;j++)
				{
					if(f[k][j]==f[0][0]) continue;
					ll op=f[i][k]+f[k][j];
					ll ol=cnt[i][k]*cnt[k][j];
//					cout<<i<<" "<<k<<" "<<j<<endl;
					if(f[i][j]>op)
					{
						f[i][j]=op;
						cnt[i][j]=ol;
					}
					else if(f[i][j]==op) cnt[i][j]+=ol;
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(f[i][j]!=f[0][0]&&cnt[i][j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
