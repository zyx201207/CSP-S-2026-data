#include<bits/stdc++.h>
namespace zcy{
	using namespace std;
	typedef long long ll;
	typedef pair<int,int> pii;
	typedef pair<ll,ll> pll;
	const int MAXN=505;
	const int MAXM=5e5+5;
	
	ll c,n,m,d,q;
	ll w[MAXM];
	ll k[MAXN];
	vector<ll>a[MAXN];	//a[i][j]:第i条线的第j个站点编号 
	vector<ll>t[MAXN];	//t[i][j]:第i条线第j站出站距离 
	ll dis[MAXN][MAXN];
	vector<pll>g[MAXM];	//g[i][j]:第i个站的第j条线编号和出站距离 

	void init(){
		memset(dis,0x3f,sizeof dis);
		for(int i=1;i<=m;i++){
			int gs=g[i].size();
			for(int x=0;x<gs;x++)for(int y=0;y<gs;y++){
				if(x==y)continue; 
				int xl=g[i][x].first,yl=g[i][y].first;
				ll xg=g[i][x].second,yg=g[i][y].second;
				dis[xl][yl]=min(dis[xl][yl],xg+yg);
//				cout<<"C "<<xl<<" "<<yl<<"\n";
			}
		}
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			for(int j=1;j<=n;j++){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[j][i]);
			}
		}
		
		//Floyd
		for(int z=1;z<=n;z++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][z]+dis[z][j]);
				}
			}
		}
	}
	
	ll query(int x,int y){
		ll xgs=g[x].size(),ygs=g[y].size();
		ll ans=LLONG_MAX;
		for(int i=0;i<xgs;i++){
			for(int j=0;j<ygs;j++){
				ll xl=g[x][i].first,yl=g[y][j].first;
				ll xg=g[x][i].second,yg=g[y][j].second;
				ans=min(ans,dis[xl][yl]+w[x]+w[y]+xg+yg);
			}
		}
		return ans;
	}
	
	inline ll read(){
		ll r=0;char t;
		t=getchar();
		while(!isdigit(t))t=getchar();
		while(isdigit(t)){
			r=r*10ll+t-'0';
			t=getchar();
		}
		return r;
	}
	
	inline void write(ll r){
		char a[20]={};
		int cnt=0;
		if(r==0){
			putchar('0');
			putchar('\n');
			return;
		}
		while(r){
			a[++cnt]=r%10+'0';
			r/=10;
		}
		for(int i=cnt;i>=1;i--)putchar(a[i]);
		putchar('\n');
	}

	int main(){
		#ifndef DEBUG
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);
		#endif

		c=read(),n=read(),m=read(),d=read(),q=read();
		for(int i=1;i<=m;i++)w[i]=read();
		for(int i=1;i<=n;i++){
			k[i]=read();
			for(int j=1;j<=k[i];j++){
				ll t1=read(),t2=read();
				a[i].emplace_back(t1);
				t[i].emplace_back(t2);
				g[t1].emplace_back(i,t2);
			}
		}
		
		init();
		
		while(q--){
			ll x=read(),y=read();
			write(query(x,y));
		}

		return 0;
	}
}
int main(){
	zcy::main();
	return 0;
}

