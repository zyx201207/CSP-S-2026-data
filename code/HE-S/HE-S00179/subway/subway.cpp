#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define MAXN 5005
#define MAXM 500005
vector<ll>lin[5005];ll n,m,d,q,c;
int hc[5005][1995];
int vis[MAXM];//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
vector<ll>station[MAXM];
ll ent[MAXM];
struct inq{
	ll now;//now station
	ll walk;// walk time
};

//讲个笑话，万圣节=圣诞节 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> ent[i];
	}
	for(int i =1;i<=n;i++){
		ll k,a,t;
		cin >> k;
		while(k--){
			cin >> a >> t;
			lin[i].push_back(a);
			hc[i][a]=t;
			station[a].push_back(i);
		}
	}
	while(q--){
		ll ans = 1e18+1;
		ll x,y;cin >> x >> y;
		queue<inq> que;
		inq start;
		start.now=x;
		start.walk = ent[x];
		vis[x] = 1;
		que.push(start);
		while(!que.empty()){
			inq now_station = que.front();
			que.pop();
			if(now_station.now==y){
				ans = min(ans,now_station.walk+ent[y]);
			}
			for(auto i:station[now_station.now]){//fr s -> line
				for(auto st : lin[i]){
					//cout << now_station.now <<"S" << i;
					if(!vis[st]&&now_station.walk+hc[i][now_station.now]<ans){
						//cout << "2s";
						vis[st]=1;
						inq tmp;
						tmp.now = st;
						tmp.walk = now_station.walk+hc[i][now_station.now]+hc[i][st];
						//if(now_station.now==x)tmp.walk-=hc[i][now_station.now-1];
						que.push(tmp);
						//printf("%d will go:%-10ld;will more walk:%-10ld;add t[%ld][%ld]+t[%ld][%ld] -> %ld+%ld\n",now_station.now,st,tmp.walk,i,now_station.now,i,st,hc[i][now_station.now],hc[i][st]);
					}
				}
			}
		}
		cout << ans << "\n";
		memset(vis,0,sizeof(vis));
	}
	/*   _____________________
	    /         |
	   /          o
	  /          /|\
	 /            | 
   \/            /\              feropen!!!!!!!(钓鱼)*/
	return 0;
}
