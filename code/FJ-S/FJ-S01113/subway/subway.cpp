#include<bits/stdc++.h>
#define ll long long
using namespace std;
void read(ll x){
	cin >> x;
	return;
}
ll n, m, q, w[1000000], dis[1000][1000], ans;
vector<pair<ll, ll> > qwq[1000000];//每个站经过的线路 
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> n >> n >> m >> q >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		ll pwp;
		cin >> pwp;
		for(int j = 1; j <= pwp; j++){
			ll state, cost;
			cin >> state >> cost;
			qwq[state].push_back(make_pair(i, cost));
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dis[i][j] = 1e16;
		}
		dis[i][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		for(auto dsa : qwq[i]){
			for(auto asd : qwq[i]){
				dis[dsa.first][asd.first] = min(dis[dsa.first][asd.first], dsa.second + asd.second);
			}
		}
	} 
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
			}
		}
	}
	for(int i = 1; i <= q; i++){
		ll dsa, asd;
		ans = 1e16;
		cin >> dsa >> asd;
		for(auto sad : qwq[dsa]){
			for(auto sda : qwq[asd]){//15:37 我这么写代码会被教练打死吧。。 
				ans = min(ans, sad.second + sda.second + dis[sad.first][sda.first]); 
			}
		}
		cout << ans + w[dsa] + w[asd] << endl;
	}
	return (0 - 0);
}
//15:03 感觉T2我的做法很对啊？？？试图证一下。最小生成树有啥性质来着？？
//15:07 好的胡的应该是假的。但是获得了一些思考进展。想起来了数据范围里的提示。
//15:08 二分图是我不熟悉的领域啊。怎么办呢？
//15:10 好诡异啊，旁边有小朋友一直在看我。 
//15:21 应该会了。比较简单啊，很暴力的样子，看着和去年T2风格差不多。绿？ 
//15:30 话说是不是11.1能看到SHELTER 35y的直播啊。会不会有新东西呢会不会呢？
//15:44 一次过了？？？爽飞/hec
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

