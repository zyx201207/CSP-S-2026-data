#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[500005];
struct node{
	int t,q,qq;
};
vector< node > v[1001];

struct tto{
	int x,ans;
};

int bfs(int sx,int tx){
	int tq[5001]={};
	queue<tto> u;
	u.push((tto){sx,v[sx][sx].qq});
	while(!u.empty()){
		tto e=u.front();
		u.pop();
		if(e.x == tx){
			return e.ans;
		}
		for(auto y:v[e.x]){
			if(tq[y.t] == 0){
				if(y.t==tx){
					return e.ans+y.q;
				}
				u.push((tto){y.t,e.ans+y.q+v[y.t][y.t].qq});
				tq[y.t] = 1;
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> p;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		int df,fd;
		cin >> df >> fd;
		v[df].push_back((node){df,fd,fd});
//		v[df].push_back(df);
		for(int j = 2;j <= k;j++){
			int a,y;
			cin >> a >> y;
			v[df].push_back((node){a,y,y});
			v[a].push_back((node){df,y,0});
//			v[a][a].qq=y;
		}
	}
	for(int i = 1;i <= p;i++){
		int sx,tx;
		cin >> sx >> tx;
		int cnt=bfs(sx,tx);
		cout << cnt+w[sx]+w[tx] << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
