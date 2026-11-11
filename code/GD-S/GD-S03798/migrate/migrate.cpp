#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,M=20;
int a[N],nxt[M][N],sum1[M][N],pre[M][N],sum2[M][N];
bool check(int l,int r)
{
	int s1=r,s2=l,pos=l;
	for(int i=13;i>=0;i--)
		if(nxt[i][pos]<r)s1+=sum1[i][pos],pos=nxt[i][pos];
	s1+=sum1[0][pos],pos=r;
	for(int i=13;i>=0;i--)
		if(pre[i][pos]>l)s2+=sum2[i][pos],pos=pre[i][pos];
	s2+=sum2[0][pos];
//	cout<<l<<' '<<r<<' '<<s1<<' '<<s2<<'\n';
	return s1-s2==1;
}
void work(int c)
{
	int n,d;cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(c>=11&&c<=12)
	{
		int dis=-1;
		for(int i=1;i<=n;i++)
			if(a[i]-a[1]<=d)dis++;
		if(dis<2){cout<<"0\n";return;}
		int ans=0;
		for(int i=1;i+2*dis-1<=n;i++)ans++;
		cout<<ans<<'\n';
		return;
	}
	for(int i=1,j=1;i<=n;i++)
	{
		j=max(j,i);
		for(;j<n&&a[j+1]-a[i]<=d;)j++;
		nxt[0][i]=j,sum1[0][i]=i;
	}
	for(int i=n,j=n;i>=1;i--)
	{
		j=min(j,i);
		for(;j>1&&a[i]-a[j-1]<=d;)j--;
		pre[0][i]=j,sum2[0][i]=i;
	}
	for(int i=1;i<=13;i++)
	for(int j=1;j<=n;j++)
	{
		nxt[i][j]=nxt[i-1][nxt[i-1][j]],sum1[i][j]=sum1[i-1][j]+sum1[i-1][nxt[i-1][j]];
		pre[i][j]=pre[i-1][pre[i-1][j]],sum2[i][j]=sum2[i-1][j]+sum2[i-1][pre[i-1][j]];
	}
	int ans=0;
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
		ans+=(check(i,j)?1:0);
	cout<<ans<<'\n';
}
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,_;cin>>c>>_;
	for(;_;_--)work(c);
	return 0;
}
/*
*/