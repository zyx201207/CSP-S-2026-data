#include<bits/stdc++.h>
#define ll long long 
#define fg cout<<"！！！！！！！！！！！！！！！！！！！！！！！！！！"<<endl
#define inf (ll)1e18
#define pb push_back
#define mk make_pair
#define pii pair<ll,ll>
using namespace std;
const int mod=998244353,N=5e5+5;
int M1;
ll n,m,d,q;
ll w[N];
int K[505];
struct str{
	int net,to;
	ll dis;
}wt[N];
int c2;
int h2[N];
ll dis[505][505];
void add2(int u,int v,int w){
	c2++;
	wt[c2].to=v;
	wt[c2].net=h2[u];
	h2[u]=c2;
	wt[c2].dis=w;
}
ll read(){
	ll n=0,k=1;
	char c;
	while(c>'9'||c<'0'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		n=(n<<1)+(n<<3)+c-'0';
		c=getchar();
	}
	return n*k;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void For_aiur(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
//		cin>>w[i];
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		K[i]=read();
		for(int j=1;j<=K[i];j++){
			ll a,t;
			a=read();t=read();
			add2(a,i,t);
		}
	} 
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=h2[i];j;j=wt[j].net){
			for(int k=h2[i];k;k=wt[k].net){
				int u=wt[j].to,v=wt[k].to;
				if(u==v) continue;
				dis[u][v]=dis[v][u]=min(dis[u][v],wt[j].dis+wt[k].dis);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		x=read();y=read();
		ll res=inf;
		for(int j=h2[x];j;j=wt[j].net){
			for(int k=h2[y];k;k=wt[k].net){
				res=min(res,w[x]+w[y]+dis[wt[j].to][wt[k].to]+wt[j].dis+wt[k].dis);
			}
		}
		write(res);
		puts("");
	}
}
int M2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio();cin.tie();
	int wlae=1,C;
	cin>>C;
//	cin>>wlae;
	while(wlae--) For_aiur();
//	cerr<<"used memory:"<<(&M1-&M2)/1024/1024<<"MB"<<endl;
	return 0;
}
/*

*/
