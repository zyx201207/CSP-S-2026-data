#include<bits/stdc++.h>//172.16.12.5
using namespace std;

#ifdef LOCAL
#define debug(x) cerr<<#x<<" = "<<(x)<<'\n';
#else
#define debug(x)
#endif
#define ll long long
#define vct vector
#define pb push_back
#define PII pair<int,int>
#define int long long

/*
#ifdef LOCAL
bool ____ST;
#endif
int n,d,ans,x[2000010],nxt[2000010],cnt[2000010],pre[2000010],lst[2000010];
#ifdef LOCAL
bool ____ED;
#endif

void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		pre[i]=lst[i]=cnt[i]=nxt[i]=0;
	}
	ans=0;
	sort(x+1,x+n+1);
	int l=0;
	for(int i=1;i<=n;i++)
	{
//		debug(x[i]);
		while(l<=n&&(l<=i||x[l]-x[i]<=d))
		{
			l++;
		}
		l--;
		nxt[i]=l;
	}
	for(int i=1;i<=n;i++)
	{
		if(nxt[i]==nxt[nxt[i]]||nxt[i]==i+1)
		{
			cnt[i]=0;
			continue;
		}
		cnt[i]=max(0ll,nxt[nxt[i]-1]-max(nxt[nxt[i]-2],nxt[i])+1);
//		debug(max(nxt[nxt[i]-2],nxt[i]));
//		debug(nxt[nxt[i]-1]);
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==1||cnt[i]==0)
		{
			pre[i]++;
			pre[nxt[i]]+=pre[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[nxt[i]]==1||cnt[nxt[i]]==0)
		{
			lst[i]+=lst[nxt[i]];
		}
		if(cnt[i]==1||cnt[i]==0)
		{
			lst[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==2)
		{
			ans+=(pre[i]+1)*(lst[nxt[nxt[i]]]+1);
		}
//		debug(i);
//		debug(cnt[i]);
//		debug(lst[i]);
//		debug(pre[i]);
//		debug(nxt[i]);
	}
	cout<<ans<<'\n';
}
*/
/*
0 1
7 5
9 6 11 0 4 2 15 
*/

#ifdef LOCAL
bool ____ST;
#endif
int n,d,ans,x[5010],mind[5010],cnt[5010],sum[5010];
#ifdef LOCAL
bool ____ED;
#endif

void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	ans=0;
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++)
	{
//		memset(mind,0x3f,sizeof(mind));
//		memset(cnt,0,sizeof(cnt));
//		memset(sum,0,sizeof(sum));
		for(int j=0;j<=n+5;j++)
		{
			cnt[j]=sum[j]=0;
			mind[j]=0x3f3f3f3f3f3f3f3f;
		}
		sum[i]=cnt[i]=1,mind[i]=0;
		int l=i,r=i;
		for(int j=i+1;j<=n;j++)
		{
			while(l<j&&x[j]-x[l]>d)
			{
				l++;
			}
			while(r<j&&(r<l||mind[r]<=mind[l]))
			{
				r++;
			}
			mind[j]=mind[l]+1;
			cnt[j]=sum[r-1]-sum[l-1];
			sum[j]=sum[j-1]+cnt[j];
			if(cnt[j]==2)
			{
//				debug(i);
//				debug(j);
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}

/*
0 1
5 2
1 2 3 4 5

*/

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	cerr<<double(&____ED-&____ST)/(1024*1024)<<"Mib\n";
	double ____st=clock();
#endif
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
#ifdef LOCAL
	double ____ed=clock();
	cerr<<'\n'<<(____ed-____st)/CLOCKS_PER_SEC*1000<<"ms\n";
#endif
	return 0;
}
