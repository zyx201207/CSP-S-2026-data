#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ms(A,b) memset(A,b,sizeof A)
#define w while
using namespace std;
const int N=5000;
int c,t;
int n,d;
ll A[N];
ll minn[N][N];
ll cnt[N][N];
void dfs(int s,int k,int bu)
{
	if(k>n) return;
	if(k!=s && minn[s][k]>=bu)
	{
		if(minn[s][k]==bu) cnt[s][k]++;
		if(minn[s][k]>bu) cnt[s][k]=1,minn[s][k]=bu;
	}
	dfs(s,k+1,bu+1);
	for(int i=k+2;i<=n;i++)
		if(A[i]-A[k]<=d) dfs(s,i,bu+1); 
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	w(t--)
	{
		ms(cnt,0);
		ms(minn,0x3f);
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>A[i];
		for(int i=1;i<=n;i++) dfs(i,i,0);
		ll ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(cnt[i][j]==2) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}

