#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 510;//subway line number
constexpr int M = 5e5 + 10;//subway station number
//d_max->20 // per position went through by subway line
int c;
int n;
int m;
int d;
int q;
int xr;
int yr;
int w[M];
int k[25];
//pair<int, int> t[M][25];
bool sub_thr[N][M];
bool visit[N];
bool visit_pos[M];
vector<vector<int>> sub_thr_pos(N);//first::throuth position num
vector<vector<pair<int, int>>> pos_th(M);//first::throuth subway line//second::using time
struct Point {
	int v;//subway line
	ll dist;
	Point(int V, ll D): v(V), dist(D) {}
	
	bool operator <(const Point &other) const {
		return dist > other.dist;
	}
};

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	/*freopen("C:\\Users\\Administrator\\Desktop\\subway5.in", "r", stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\ans.txt", "w", stdout);*/
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		int position_num, using__time;
		for(int h = 1; h <= k[i]; h++) {
			cin >> position_num >> using__time;
			
			sub_thr[i][position_num] = true;
			sub_thr_pos[i].push_back(position_num);
			pos_th[position_num].push_back(pair<int, int> {i, using__time});
		} 
	}
	while(q--) {
		memset(visit, false, sizeof(visit));
		memset(visit_pos, false, sizeof(visit_pos));
		cin >> xr >> yr;
		priority_queue<Point> p;
		for(auto &line: pos_th[xr]) {
			p.emplace(line.first, line.second + w[xr]);
		}
		
		while(!p.empty()) {
			Point temp = p.top();
			p.pop();
			int l = temp.v;
			int d = temp.dist;
			if(visit[l])
				continue;
			visit[l] = true;
			
			if(sub_thr[l][yr]) {
				for(auto &line: pos_th[yr]) {
					if(l == line.first) {
						cout << d + line.second + w[yr] << '\n';
					}
				}
				break;	
			}
			
			for(auto &pos: sub_thr_pos[l]) {
				if(visit_pos[pos])
					continue;
				visit_pos[pos] = true;
				ll t_l_to_pos = 0;
				
				for(auto &line: pos_th[pos]) {
					if(line.first == l){
						t_l_to_pos = line.second;
						break;
					}
				}
				
				for(auto &line: pos_th[pos]) {
					p.emplace(line.first, d + t_l_to_pos + line.second);
				}
			}
		}

	}
	
	
	return 0;
}
