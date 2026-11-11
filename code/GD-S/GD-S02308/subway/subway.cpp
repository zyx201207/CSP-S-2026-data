#include <bits/stdc++.h>
#define endl '\n'
#define lint long long
using namespace std;
const int N = 5e2+5;
const int M = 5e5+5;

struct node{
	lint x,y;
};

int c,n,m,d,q;
lint w[M];
int k[N];
vector<node> t[N]; // 一条线路的所有地铁站以及站台站厅的时间 
lint a[N][N]; // a[i][j] 表示 i 线路到 j 线路上最短的时间
vector<node> b[M]; // 一个地铁站经过的所有线路以及站台站厅的时间 
map<int,lint > ma[M]; // 一个地铁站站厅到某个线路的时间 
map<pair<int,int>,int > an;

bool is[N];

inline void dfs(int x){
	for(int i = 1; i <= n; i++)
		is[i] = 0;
	is[x] = 1;
	priority_queue<pair<lint,int >,vector<pair<lint,int >>,greater<pair<lint,int >> > q;
	for(int i = 1; i <= n; i++)
		if(i != x && a[x][i] != 0x7f7f7f7f)
			q.push(make_pair(a[i][x],i));
//	cout << q.top().first << " " << q.top().second << endl;
	for(int T = 1; T < n; T++){
		while(is[q.top().second])
			q.pop();
		int to = q.top().second;
		a[x][to] = min(a[x][to],q.top().first);
		is[to] = true;
		q.pop();
		for(int i = 1; i <= n; i++){
			if(!is[i] && a[to][i] != 0x7f7f7f7f)
				q.push(make_pair(a[x][to]+a[to][i],i));
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i]; 
		b[i].push_back((node){0,0});
	}
	
	memset(a,0x7f7f7f7f,sizeof(a));
	
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		t[i].push_back((node){0,0});
		a[i][i] = 0;
			
		for(int j = 1; j <= k[i]; j++){
			int x,y;
			cin >> x >> y;
			t[i].push_back((node){x,y});
			b[x].push_back((node){i,y}); 
			ma[x][i] = y;
		}
	}
	
	if(n <= 2){
		lint mi = 0x7f7f7f7f;
		for(int i = 1; i <= m; i++){
			if(b[i].size() == 2) continue;
			mi = min(mi,ma[i][1]+ma[i][2]);
		}
		int x,y;
		while(q--){
			cin >> x >> y;
			if(b[x].size() == 2 && b[y].size() == 2)
				cout << w[x] + w[y] + ma[x][b[x][1].x] + ma[y][b[y][1].x] + (b[x][1].x == b[y][1].x ? 0 : mi) << endl;
			else if(b[x].size() == 3 && b[y].size() == 3)
				cout << w[x]+w[y] + min(min(ma[x][1]+ma[y][1],ma[x][2]+ma[y][2]),mi+min(ma[x][1]+ma[y][2],ma[x][2]+ma[y][1])) << endl;
			else{
				if(b[x].size() == 2) cout << w[x] + w[y] + ma[x][b[x][1].x] + min(ma[y][b[x][1].x],ma[y][(b[x][1].x==1?2:1)] + mi) << endl;
				else cout << w[x] + w[y] + ma[x][b[x][2].x] + min(ma[y][b[x][1].x],ma[y][(b[x][1].x==1?2:1)] + mi) << endl;
			}
		}
		return 0;
	}
	
//	if(c >= 12 && c <= 19){
//		
//		return 0;
//	}
	
	
	
//	for(int i = 1; i <= n; i++){
//		cout << i << ": ";
//		for(int j = 1; j <= k[i]; j++){
//			cout << t[i][j].x << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	for(int i = 1; i <= m; i++){
//		cout << i << ": ";
//		for(int j = 1; j < b[i].size(); j++){
//			cout << b[i][j].x << " ";
//		}
//		cout << endl;
//	}

	for(int i = 1; i <= m; i++){
		for(int j = 1; j < b[i].size()-1; j++){
			for(int z = j+1; z < b[i].size(); z++){
				a[b[i][j].x][b[i][z].x] = min(a[b[i][j].x][b[i][z].x],ma[i][b[i][j].x]+ma[i][b[i][z].x]);
				a[b[i][z].x][b[i][j].x] = a[b[i][j].x][b[i][z].x];
			}
		}
	}
	
	for(int i = 1; i <= n; i++)
		dfs(i);

//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			if(a[i][j] != 0x7f7f7f7f){
//				cout << i << "->" << j << ": " << a[i][j] << endl;
//			}
//		}
//	}

	if(q > 2000){
		int x,y;
		while(q--){
			cin >> x >> y;
			if(x > y) swap(x,y);
			pair<int,int > P = make_pair(x,y);
			if(an.find(P) != an.end()){
				cout << an[P] << endl;
				continue;
			}
			if(b[x].size() == 2 && b[y].size() == 2)
				cout << an[P] = (w[x] + w[y] + ma[x][b[x][1].x] + ma[y][b[y][1].x] + (b[x][1].x == b[y][1].x ? 0 : a[b[x][1].x][b[y][1].x])) << endl;
			else if(b[x].size() == 3 && b[y].size() == 3){
				lint mi = 0x7f7f7f7f;
				for(int i = 1; i < b[x].size(); i++)
					for(int j = 1; j < b[y].size(); j++)
						mi = min(mi,a[b[x][i].x][b[y][j].x] + ma[x][b[x][i].x] + ma[y][b[y][j].x]);
				cout << an[P] = (mi + w[x] + w[y]) << endl;
			}else{
				if(b[x].size() != 2) swap(x,y);
				lint mi = 0x7f7f7f7f;
				for(int i = 1; i < b[y].size(); i++)
					mi = min(mi,a[b[x][2].x][b[y][i].x] + ma[y][b[y][i].x]);
				lint ans = mi + w[x] + w[y] + ma[x][b[x][2].x];
				cout << ans << endl;
				if(x > y) swap(x,y);
				an[P] = ans;
			}
		return 0;
	}

	int x,y;
	while(q--){
		cin >> x >> y;
		if(b[x].size() == 2 && b[y].size() == 2)
			cout << w[x] + w[y] + ma[x][b[x][1].x] + ma[y][b[y][1].x] + (b[x][1].x == b[y][1].x ? 0 : a[b[x][1].x][b[y][1].x]) << endl;
		else if(b[x].size() == 3 && b[y].size() == 3){
//			cout << w[x]+w[y] + min(min(ma[x][1]+ma[y][1],ma[x][2]+ma[y][2]),mi+min(ma[x][1]+ma[y][2],ma[x][2]+ma[y][1])) << endl;
			lint mi = 0x7f7f7f7f;
			for(int i = 1; i < b[x].size(); i++)
				for(int j = 1; j < b[y].size(); j++)
					mi = min(mi,a[b[x][i].x][b[y][j].x] + ma[x][b[x][i].x] + ma[y][b[y][j].x]);
			cout << mi + w[x] + w[y] << endl;
		}else{
//			if(b[x].size() == 2) cout << w[x] + w[y] + ma[x][b[x][1].x] + min(ma[y][b[x][1].x],ma[y][(b[x][1].x==1?2:1)] + mi) << endl;
//			else cout << w[x] + w[y] + ma[x][b[x][2].x] + min(ma[y][b[x][1].x],ma[y][(b[x][1].x==1?2:1)] + mi) << endl;
			if(b[x].size() != 2) swap(x,y);
			lint mi = 0x7f7f7f7f;
			for(int i = 1; i < b[y].size(); i++)
				mi = min(mi,a[b[x][2].x][b[y][i].x] + ma[y][b[y][i].x]);
			cout << mi + w[x] + w[y] + ma[x][b[x][2].x] << endl;
		}
	}
	return 0;
}
