#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fileIO(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}
const int N = 1e3;
int nums[N][N];
int w[N];
int time1[N];
int time2[N];
int lines[N];
struct Node{
	int pos,time;
};
queue<Node> que;
Node poss[N];
int c,n,m,d,q;
int bfs(int pos,int time,int pos1){
	que.push({pos,time});
	Node t;
	while(!que.empty()){
		t = que.front();
		if (t.pos == pos1){
			return t.time;
		}
		que.pop();
		for (int i = 1;i<=m;i++){
			if (nums[t.pos][i] == 1){
				que.push({i,poss[i].time+t.time});
			}
		}
	}
}

int main(){
	fileIO("subway");
	fastIO();

	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i<=m;i++){
		cin >> time1[i];
		poss[i].time+=time1[i];
	}
	for (int i = 1;i<=n;i++){
		int f;
		cin >> f;
		for (int j = 1;j<=f;j++){
			cin >> lines[i] >> time2[i];
			poss[lines[i]].time+=time2[i];
		}
		for (int k = 1;k<=f;k++){
			for (int j = k+1;j<=f;j++){
				nums[k][j] = 1;
				nums[j][k] = 1;

			}
		}


	}
	for (int i = 1;i<=m;i++){
		poss[i].pos = i;
	}
	int a,b;
	for (int i = 1;i<=q;i++){
		cin >> a >> b;
		cout << bfs(a,poss[a].time,b) << '\n';
	}








	return 0;
}
