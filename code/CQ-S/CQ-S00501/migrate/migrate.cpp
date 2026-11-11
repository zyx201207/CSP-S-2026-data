//100 at 16:22
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PIL pair<int,ll>
#define PLI pair<ll,int>
#define fi first
#define se second 
using ll=long long;
using ull=unsigned long long;
using ld=long double;
#define FILE "migrate"
// #define FOR_ONLINE
// #define TEST_FOR_MS
// #define freopen(x) feropen(x)
bool mst;
const int N=2e6+5;
ll c,T;
ll n,d,x[N],nxt[N],ans;
int dp[N][2][3][4];
int DP(int now,int x,int y,int z){
	// cerr<<now<<" "<<x<<" "<<y<<" "<<z<<"\n";
	if(now==n||z==0||z==3)	return 0;
	if(dp[now][x][y][z]!=-1)	return dp[now][x][y][z];
	int nx=x?nxt[now-2]:now,ny=y?nxt[now-1]:now,nz=nxt[now];
	int vx=0,vy=0,vz=0,ret=0;
	if(nz>now)	vz=min(3,z+y*(ny==nz)+x*(nx==nz));
	if(nz-1>now)	vy=min(2,z+y*(ny>=nz-1)+x*(nx>=nz-1));
	if(nz-2>now)	vx=min(1,z+y*(ny>=nz-2)+x*(nx>=nz-2));
	if(z==2)	ret+=nz-ny;
	else if(y==1)	ret+=ny-nx;
	return dp[now][x][y][z]=ret+DP(nz,vx,vy,vz);
}
void Main(){
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++)	cin>>x[i],nxt[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<3;k++){
				for(int l=0;l<4;l++)	dp[i][j][k][l]=-1;
			}
		}
	}
	int r=n;
	for(int i=n;i>=1;i--){
		while(x[r]-x[i]>d)	r--;
		nxt[i]=r;
	}
	// for(int i=1;i<=n;i++)	cerr<<nxt[i]<<" ";cerr<<"\n";
	for(int i=1;i<=n;i++)	ans+=DP(i,0,0,1);
	cout<<ans<<"\n";
}
bool med;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
#ifndef FOR_ONLINE
#ifndef TEST_FOR_MS
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
#else
	string x;cin>>x;
	freopen(("down/"FILE"/"FILE+x+".in").c_str(),"r",stdin);
	freopen(FILE".out","w",stdout);
#endif
#endif
	cerr<<fixed<<setprecision(6)<<abs(&med-&mst)/1024.0/1024<<"MB\n";
	double st=clock();
	cin>>c>>T;
	while(T--)  Main();
	cerr<<fixed<<setprecision(6)<<(clock()-st)/CLOCKS_PER_SEC<<"s\n";
}
/*
WorldMachine suki

11.4 是我的生日，整理迷惑行为大赏的能祝我生日快乐吗

许愿世界机器可以天天开心啊

我去怎么 300 了，那再许个愿让我 AK -S 好不好
*/