#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,a[2000010],d[10010],p[10010],ans;
void dfs(int x,int k)
{
	//cout<<' '<<x<<' '<<k<<endl;
	if(k<d[x]) d[x]=k,p[x]=1;
	else if(k==d[x]) p[x]++;
	if(x>n)
	{
		//cout<<"!"<<x<<endl;
		return;
	}
	int l=0;
	//cout<<"x-1"<<a[x]<<endl;
	while(a[x+l+1]-a[x]<=m&&x+l+1<=n)
	{
		//cout<<"x+l+1"<<a[x+l+1]<<endl;
		l++;
		dfs(x+l,k+1);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==11||c==12)
		{
			int kk=a[2]-a[1];
			if(m/kk<=1) cout<<0<<endl;
			else cout<<max(0ll,n-2*m/kk+1)<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				d[j]=1e18,p[j]=0;
			dfs(i,0);
			//cout<<i<<endl;
			for(int j=1;j<=n;j++)
			{
				//cout<<d[j]<<' '<<p[j]<<endl;
				if(p[j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
/*
0 3
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63

*/
