#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+10,M=5e5+10;
ll w[M],k[M];
ll a[N][N],t[N][N];
ll cnt[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	
	
	for(int x=1;x<=n;x++)
	{
		for(int i=1;i<=k[x];i++)
		{
			for(int j=i+1;j<=k[x];j++)
			{
			int l=a[x][i],r=a[x][j];
			cnt[l][r]=w[l]+t[x][i]+t[x][j]+w[r];
			cnt[r][l]=cnt[l][r];
			}
		}
	}
	
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=cnt[x][y];
		if(ans==0) ans=1e10;
		for(int i=1;i<=m;i++)
		{
			if(i==x||i==y) continue;
			if(cnt[x][i]==0||cnt[i][y]==0) continue;
			ans=min(ans,cnt[x][i]+cnt[i][y]-2*w[i]);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

