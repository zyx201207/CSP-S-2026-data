#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define int long long
#define fi first
#define se second
typedef std::pair<int,int> pii;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (int)1e3+10;
const int MAXM = (int)5e5+10;

int read(){
	int x=0,f=1;char c = getchar();
	for(;!isdigit(c);c=getchar()) if(c == '-') f = -1;
	for(;isdigit(c);c=getchar()) x = (x<<3)+(x<<1)+(c^48);
	return x*f;
} 
template<typename T>
void write(T x){
	if(x<0){putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void IO(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
}

int c,n,m,d,q,x,y,k;
int tmp,ans;
int flag[MAXM],dis[MAXN][MAXN];//flag入队标记,dis路线间最短路 
int weight[MAXN],a[MAXN][30],t[MAXN][30];//第i条路线，第j个站到站台时间 
std::vector<pii>route[MAXM];//pair(点i所属路线编号,下车时间) 
std::queue<int>que;

/*
线路间最短距离
floyd
线路之间只能通过交点转移 
*/

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
signed main(){
	IO();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	FOR(i,1,m+1){
		cin>>weight[i];
//		printf("i=%lld,weight=%lld\n",i,weight[i]);
		flag[i]=0;
	}
	
	FOR(i,1,n+1){
		FOR(j,1,n+1) dis[i][j] = INF;
		dis[i][i] = 0;
	}
	
	FOR(i,1,n+1){
		cin>>k;
		FOR(j,1,k+1){
			cin>>a[i][j]>>t[i][j];
			tmp = a[i][j];//被操作站			
			route[tmp].emplace_back(i,t[i][j]);
			if(!flag[tmp] && route[tmp].size()>1) que.push(tmp),++flag[tmp];
		}
	} 
	
	while(!que.empty()){
		int now = que.front();
		que.pop();
		for(const pii& u : route[now]){
			for(const pii& v : route[now]){//路线u.fi -> 路线v.fi
				if(u.fi == v.fi) continue;
				
				dis[u.fi][v.fi] = min(dis[u.fi][v.fi],u.se+v.se);
//				printf("now=%lld,u=%lld,v=%lld,d=%lld\n",now,u.fi,v.fi,dis[u.fi][v.fi]);
			}
		}
	}
	
	FOR(k,1,n+1){
		FOR(i,1,n+1){
			if(i == k) continue;
			FOR(j,1,n+1){
				if(j <= i||j == k) continue;
				dis[i][j] = dis[j][i] = min(dis[i][j],dis[i][k] + dis[k][j]);
//				if(i<150&&j<150&&k<150)
//					printf("k=%lld,i=%lld,j=%lld,d=%lld,d=%lld,d=%lld\n",k,i,j,dis[i][j],dis[i][k],dis[k][j]);
				
			}
		}
	}
	
	while(q--){
		cin>>x>>y;
		ans = INF;
		for(const pii& u : route[x])
			for(const pii& v : route[y]){
				ans = min(ans,u.se+v.se+dis[u.fi][v.fi]);
//				printf("u=%lld,v=%lld,ans=%lld\n",u.fi,v.fi,ans);
			}
//		printf("t=%lld,%lld,%lld,%lld,ans=%lld\n",x,y,weight[x],weight[y],ans+weight[x]+weight[y]);
		cout<<(ans+weight[x]+weight[y])<<'\n';
	}
	return 0;
}

