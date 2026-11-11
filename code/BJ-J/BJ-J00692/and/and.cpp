#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool vis[40][N];
bool b[N],tmp[N];
long long a[N];
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		long long t=a[i];
		int cnt=0;
		while(t)
		{
			vis[cnt][i]=(t&1);
			t>>=1;
			cnt++;
		}
	}
	memset(b,1,sizeof(b));
	for(int i=40;i>=0;i--)
	{
		memset(tmp,0,sizeof(tmp));
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[i][j] && b[j])
			{
				cnt++;
				tmp[j]=1;
			}
		}
		if(cnt>=m)
		{
			for(int j=1;j<=n;j++)
			{
				b[j]=tmp[j];
			}
		}
	}
	long long ans=LLONG_MAX;
	for(int i=1;i<=n;i++)
	{
		if(b[i])
		{
			ans&=a[i];
		}
	}
	if(ans==LLONG_MAX) cout<<0;
	else cout<<ans;
	return 0;
}
