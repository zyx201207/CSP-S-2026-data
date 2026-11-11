#include<bits/stdc++.h>
using namespace std;
const long long _MAX = 5e5+5;
#define ll long long
#define ull unsigned long long

struct _Q{
	ll x , y , id , ans;
}Q[_MAX];

ll c , n , m , d, q , w[_MAX] , k , a , t , dis[2*_MAX];
bool flag[2*_MAX] , fflag[2*_MAX];
vector< pair<ll,ll> > e[2*_MAX];
queue <ll> qe;

bool cmp1(_Q a , _Q b){
	return a.x < b.x;
}

bool cmp2(_Q a , _Q b){
	return a.id < b.id;
}

void dj(ll x){
	memset(dis,0x7f,sizeof(dis));memset(flag,0,sizeof(flag));memset(fflag,0,sizeof(fflag));
	dis[x] = 0;
	qe.push(x);
	while(qe.size()){
		ll u = qe.front();
		qe.pop();
		fflag[u] = 0;
		for (int i = 0 ; i < e[u].size() ; i ++){
			pair<ll,ll> v = e[u][i];
			if (dis[v.first] > dis[u] + v.second){
				dis[v.first] = dis[u] + v.second;
				if (!fflag[v.first]){
					qe.push(v.first);
					fflag[v.first] = 1;
				}
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= m ; i ++){
		cin >> w[i];
	}
	for (int i = 1 ; i <= n ; i ++){
		cin >> k;
		for (int j = 0 ; j < k ; j ++){
			cin >> a >> t;
			e[a].push_back({m+i,t});
			e[m+i].push_back({a,t});
		}
	}
	for (int i = 0 ; i < q ; i ++){
		cin >> Q[i].x >> Q[i].y;
		Q[i].id = i;
	}
	sort(Q,Q+q,cmp1);
	for (int i = 0 ; i < q ; i ++){
		if (i == 0 || Q[i].x != Q[i-1].x){
			dj(Q[i].x);
		}
		Q[i].ans = dis[Q[i].y] + w[Q[i].x] + w[Q[i].y];
	}
	sort(Q,Q+q,cmp2);
	for (int i = 0 ; i < q ; i ++){
		cout << Q[i].ans << '\n';
	}
	return 0;
}
