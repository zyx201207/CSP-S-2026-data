//T3
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(a,b,c) for(int a=(b);a<=(c);a++)
const int N=2e6;
const int inf=0x7fffffff;
using namespace std;
/*
如果小的话，可以先暴力跑floyd 
先把暴力写出来，再找恰好两次的性质，很像线段树优化建图，看看在图上怎么跑 
*/
int n,d;
int ans;
int pos[N+5];
int dis[1005][1005],ways[1005][1005];
int gunmu,t;
void init_dis()
{
	rep(i,1,n) rep(j,1,n) dis[i][j]=inf,ways[i][j]=0;
	rep(i,1,n) dis[i][i]=0,ways[i][i]=1;
	return ;
}
void floyd()
{
	ans=0;
	init_dis();
//	rep(i,1,n) cin>>pos[i];
	rep(i,1,n)
	{
		rep(j,1,n)
		{
			if(i==j) continue;
			if(abs(pos[i]-pos[j])<=d) dis[i][j]=dis[j][i]=1,ways[i][j]=ways[j][i]=1;
		}
	}
//	rep(i,1,n)
//	{ 
//		rep(j,1,n) cout<<((dis[i][j]!=inf)?dis[i][j]:-1)<<" ";
//		cout<<"\n";
//	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(k==i || k==j || i==j) continue;
				int cost=dis[i][k]+dis[k][j];
				if(cost<dis[i][j]) ways[i][j]=ways[i][k]*ways[j][k],dis[i][j]=cost;
				else if(cost==dis[i][j]) ways[i][j]+=ways[i][k]*ways[j][k];
//				cout<<k<<" "<<i<<" "<<j<<":"<<dis[i][j]<<" "<<ways[i][j]<<"\n";
			}
//	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout<<i<<" "<<j<<":"<<dis[i][j]<<" "<<ways[i][j]<<"\n";
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(ways[i][j]==2) ans++;
	cout<<ans<<"\n"; //没问题了 
}
void input()
{
	cin>>n>>d;
//	cout<<"sldjlsdlf\n"; 
	rep(i,1,n) cin>>pos[i];
//	cout<<"sdlsjdfl\n";
}
void dengcha()
{
	ans=0;
	int cha=pos[2]-pos[1];
	int fff=d/cha; 
//	cout<<fff<<"\n";
//	int sx=n-
	if(cha>d) cout<<0<<"\n";
	else if(fff==0 || fff==1 || n-fff-fff+1<=0) cout<<0<<"\n";
	else cout<<n-fff-fff+1<<"\n";
}
signed main()
{
	cin.tie(0)->sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>gunmu>>t;
	while(t--) 
	{
		input(); 
		if(n<=300) 
		{
			floyd();
			continue;
		}
		bool flag=1;
		for(int i=3;i<=n;i++) if(pos[i]-pos[i-1]!=pos[i-1]-pos[i-2]) flag=0;
		if(flag) dengcha();
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5

0 1
9 4
1 2 3 4 5 6 7 8 9
*/
