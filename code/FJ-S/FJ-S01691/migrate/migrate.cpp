#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

map<int,vector<vector<int>>> path[2000002];
map<pair<int, int>, int> bgedlt;

void goon(int ls) {
	const auto pmap = path[ls-1];
	for(auto i = pmap.begin(); i != pmap.end(); i++) {
		const auto &p = i->second;
		const int new_begin = i -> first;
		for(auto j = p.begin(); j != p.end(); j++) {
			const int path_end = *(j->end()-1);
			const auto &nxtpath = path[1][path_end];
			for(auto k = nxtpath.begin(); k!=nxtpath.end();
				k++){
				const int new_end = *(k->end()-1);
				if(!bgedlt.count({new_begin,new_end})||
					bgedlt[{new_begin,new_end}]==ls){
					vector<int> copyj(*j);

					copyj.push_back(new_end);
					path[ls][new_begin].emplace_back(copyj);
					bgedlt[{new_begin,new_end}]=ls;
				}
			}
		}
	}
}

void solution() {
	int n;long long d;cin >> n >> d;
	vector<long long> x(n);
	for(auto &i: x) {
		cin >> i;
	}
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n && (x[j]-x[i]) <= d; j++){
			path[1][i].emplace_back(vector<int>{j});
			bgedlt[{i,j}] = 1;
		}
	}

	for(int ls=2; ls < n+1; ls++){
		goon(ls);
	}
	
	int sum = 0;
	for(int i=1; i < n+1; i++) {
		for(auto j=path[i].begin();j!=path[i].end();j++) {
			map<pair<int, int>, int> count;
			set<pair<int, int>> only2;
			for(auto k=j->second.begin();k!=j->second.end();
				k++) {
				const int end = *(k->end()-1);
				const pair<int, int> ap = {j->first, end};
				
				if(count[ap]==0)
					only2.insert(ap);
				else if(count[ap]==2)
					only2.erase(ap);
				
				count[ap]++;
			}

			for(auto i=only2.begin();i!=only2.end();i++){
				if(count[*i] == 2){
					sum++;
				}
			}
		}
	}

	cout << sum << '\n';

	for(int i=0; i< n+2;i++) {
		path[i].clear();
	}
	bgedlt.clear();
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, t;
	cin >> c >> t;
	while (t--){
		solution();
	}
}