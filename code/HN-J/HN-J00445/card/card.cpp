#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10, M = 3e5+10;
int n, m, data[N], sum[M];
bool vis[M];
vector<int> s;

signed main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> data[i];
	}
	for(int o = 0; o < n; o++){
		memset(vis, 0, sizeof(vis));
		//for(int i = 1; i <= n; i++) cout << vis[i];
		s.clear();
		for(int i = o+1; i <= n; i++){
			if(!vis[data[i]]){
				vis[data[i]] = 1;
				s.push_back(data[i]);
			}
			else{
				int tp = s[s.size()-1];
				while(tp != data[i] and !s.empty()){
					int tp = s[s.size()-1];
					s.pop_back();
					vis[tp] = 0;
				}
				s.push_back(data[i]);
			}
		}
		while(!s.empty()){
			sum[s[s.size()-1]]++;
			cout << s[s.size()-1] << " ";
			s.pop_back();
		}
		cout << "\n";
	}
	for(int i = 1; i <= m; i++) cout << sum[i] << " ";
	return 0;
}
