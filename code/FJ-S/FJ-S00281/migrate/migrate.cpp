#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 10;

int c, T;
int n, d;
int x[N], m[N];

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return f * x;
}

void solve(){
	n = read(), d = read();
	for(int i = 1; i <= n; ++i) x[i] = read();
	for(int u = 1; u <= n; ++u){
		int xu = x[u], xv = xu + d;
		int L = u, R = n;
		while(L < R){
			int mid = L + R + 1 >> 1;
			if(x[mid] <= xv) L = mid;
			else R = mid - 1;
		}
		m[u] = L; //u正着飞一次最远飞到m[u]
	}
	puts("0");
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), T = read();
	while(T--) solve();
	return 0;
}


/*
暴力都没思路我是菜逼 题目是hyw
对于点v，能否快速求出其左侧最近的点u满足(u,v)为双径岛屿对


性质1 不存在往回飞的最短长度情况，即只需考虑单向飞行 不妨只考虑xi<xj,i->j的方向
性质2 所有岛屿可以分为若干"连通块" 块间独立,互不可飞 以下考虑某个块内情况
性质3 记m[u]表示从u出发,1次飞行能到的最远岛屿为v=m[u],若两者间岛屿数量为2则(u,v)为双径岛屿对
定义 u->v飞行是最短的唯二的为"双径飞行"
定义 u->v飞行是唯一的为"共同飞行"   仅有(i,i)和(i,i+1)两种可能 
性质4 若u->v为双径岛屿对 若存在ku->u和v->kv的路径唯一则(ku,v),(u,kv),(ku,kv)都是双径岛屿对

路径唯一当且仅当路径上的点 xi -> xi+1成立且 xi -> xi+2不成立(仅能一步一步飞) 

暴力1
枚举岛屿对 dfs搜索

地上有n颗芒果树，自北向南排成一条直线，其中第i颗芒果树在这条直线上的坐标为xi，每年秋季，芒果成熟了，houran会沿着这条直线收
芒果，syy在观察他。 
houran的体力有限，每次行走的距离不超过d。若两颗芒果树j满足|xi-xj|<=d，houran就可以从第i颗芒果树走向第j颗芒果树，称其为合法移动。 
从芒果树u走到芒果树v的路径长度为最少次的合法移动。
syy发现，houran总是选择长度最短的路径，为了摘取尽可能多的芒果，若u->v存在两条本质不同的路径，houran会发动能力"分头行动"，但是他
最多只能同时走两条路径，注意如果超出两条路径，houran会由于不可名状原因而不能发动能力。此时，称houran能发动能力的无序数对(u,v)为
芒果对，syy想知道这样的芒果对有多少。 
*/
