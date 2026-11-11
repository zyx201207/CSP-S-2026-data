#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
ll dis[505][505];
int w[(int)5e5+5];
vector<int>a[(int)5e5+5];
unordered_map<int,int>t[(int)5e5+5];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
//	ll cnt=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
//		cnt++;
		cin>>w[i];
	}
//	cerr<<"here:"<<endl;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int aa,tt;
			cin>>aa>>tt;
			a[aa].push_back(i);
			t[aa][i]=tt;
//			cnt++;
		}
	}
//	cerr<<"here:"<<endl;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
//		cnt++;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j:a[i])
		{
			for(int k:a[i])
			{
				if(k==j)continue;
				dis[j][k]=t[i][j]+t[i][k];
//				cnt++;
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
//				cnt++;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	int tmp=-1;
//	for(int i=1;i<=m;i++)
//	{
//		tmp=max(tmp,(int)a[i].size());
//	}
//	cerr<<tmp<<endl;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=w[x]+w[y];
		ll minn=LLONG_MAX;
		for(int i:a[x])
		{
			for(int j:a[y])
			{
//				cnt++;
				ll res=t[x][i]+t[y][j]+dis[i][j];
				minn=min(minn,res);
			}
		}
		ans=ans+minn;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
