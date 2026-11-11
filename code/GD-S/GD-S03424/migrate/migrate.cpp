#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7; 
int c,T,n,d,a[N],dis[N],cnt[N],ans,t;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> T;
	int i,j,k;
	while(T--)
	{
		cin >> n >> d; t++; ans=0;
		for(i=1;i<=n;i++) cin >> a[i];
		for(i=1;i<=n;i++)
		{
			int L=i,R=n;
			for(j=i;j<=n;j++) dis[j]=LLONG_MAX,cnt[j]=0;
			cnt[i]=1; dis[i]=0;
			for(j=i;j<=n;j++)
			{
				if(cnt[j]==0) break;
				L=max(L,j+1);
				for(k=L;k<=n;k++)
				{
					if(a[k]-a[j]>d) break;
					if(dis[k]<=dis[j]) { L=k+1; continue; }
					dis[k]=dis[j]+1; cnt[k]+=cnt[j];
				}
			}
			for(j=i;j<=n;j++) {  if(cnt[j]==2) ans++; }
		}
		cout << ans << '\n';
	}
	return 0;
}
