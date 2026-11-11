#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
bool a[maxn][35];
bool vis[maxn],s[35];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long n,m;
	cin>>n>>m;
	long long x;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		long long j=0;
		while(x>0)
		{
			a[i][j]=x%2;
			j++;
			x/=2;
		}
		vis[i]=1;
	}
	for(int i=29;i>=0;i--)
	{
		long long t=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==0)continue;
			t+=a[j][i];
		}
		if(t<m)continue;
		for(int j=1;j<=n;j++)if(a[j][i]==0)vis[j]=0;
		s[i]=1;
	}
	long long l=1,ans=0;
	for(int i=0;i<=29;i++)
	{
		ans+=(l*s[i]);
		l*=2;
	}
	cout<<ans;
	return 0;
}
