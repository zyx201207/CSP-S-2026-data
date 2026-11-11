#include<cstdio>
#include<vector>
typedef long long ll;
namespace my{
	template<typename now_type>now_type max(now_type x,now_type y){return x>y?x:y;}
	template<typename now_type>now_type min(now_type x,now_type y){return x<y?x:y;}
	template<typename now_type>void read(now_type &val){
		char c=getchar();
		int nowsign=1;
		val=0;
		while(c<'0'||c>'9'){
			if(c=='-') nowsign=-1;
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			val=val*10+c-'0';
			c=getchar();
		}
		val*=nowsign;
		return;
	}
};
const ll llinf=1e18;
std::vector<std::vector<ll>>subway_dis;
std::vector<std::vector<std::pair<int,ll>>>station;
std::vector<ll>entrance_dis;
void solve(){
	int n,m,d,q;
	my::read(n);
	my::read(m);
	my::read(d);
	my::read(q);
	entrance_dis.assign(m+1,0);
	station.assign(m+1,std::vector<std::pair<int,ll>>());
	for(int i=1;i<=m;i++) my::read(entrance_dis[i]);
	subway_dis.assign(n+1,std::vector<ll>(n+1,llinf));
	for(int i=1;i<=n;i++) subway_dis[i][i]=0;
	for(int i=1;i<=n;i++){
		int tot;
		my::read(tot);
		for(int j=1;j<=tot;j++){
			int now_station;
			ll now_dis;
			my::read(now_station);
			my::read(now_dis);
			station[now_station].push_back({i,now_dis});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)station[i].size();j++){
			for(int k=j+1;k<(int)station[i].size();k++){
				std::pair<int,ll>fir=station[i][j];
				std::pair<int,ll>sec=station[i][k];
				subway_dis[fir.first][sec.first]=my::min(subway_dis[fir.first][sec.first],fir.second+sec.second);
				subway_dis[sec.first][fir.first]=my::min(subway_dis[sec.first][fir.first],fir.second+sec.second);
			}
		}
	}/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("dis[%d][%d]=%lld\n",i,j,subway_dis[i][j]);
		}
	}*/
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				subway_dis[i][j]=my::min(subway_dis[i][j],subway_dis[i][k]+subway_dis[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		my::read(u);
		my::read(v);
		ll res=llinf;
		for(std::pair<int,ll>i:station[u]){
			for(std::pair<int,ll>j:station[v]){
				int subway1=i.first;
				int subway2=j.first;
				res=my::min(res,subway_dis[subway1][subway2]+i.second+j.second);
			}
		}
		res+=entrance_dis[u]+entrance_dis[v];
		printf("%lld\n",res);
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;scanf("%d",&c);
	int T=1;
//	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
