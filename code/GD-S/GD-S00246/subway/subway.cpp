#include <bits/stdc++.h>
#define int long long
using namespace std;

struct n{
	int v, w;
	
//	bool operator () (const n l1, const n l2) const {
//		return l1.w > l2.w;
//	}
};

//vector<int> dij(const vector<vector<n>> &g, int a, int u){
//	vector<int> dis(a, 1LL << 60);
//	priority_queue<n, vector<n>, n> q;
//	
//	q.push({u, dis[u] = 0});
//	
//	while(q.size()){
//		const auto [i, l] = q.top();
//		q.pop();
//		
//		if(l > dis[i])
//			continue;
//		
//		for(const auto & [j, w] : g[i])
//			if(dis[i] + w < dis[j])
//				q.push({j, dis[j] = dis[i] + w});
//	}
//	
//	return dis;
//}

vector<int> spf(const vector<vector<n>> &g, int a, int u){
	vector<int> dis(a, 1LL << 60);
	vector<unsigned char> inq(a, 0);
	deque<int> q;
	q.push_front(u);
	dis[u] = 0;
	inq[u] = 1;
	
	while(q.size()){
		const int i = q.front();
		q.pop_front();
		
		inq[i] = 0;
		
		for(const auto & [j, w] : g[i])
			if(dis[i] + w < dis[j]){
				dis[j] = dis[i] + w;
				
				if(!inq[j]){
					if(q.empty() || dis[q.front()] < dis[j])
						q.push_back(j);
					else
						q.push_front(j);
					
					inq[j] = 1;
				}
			}
	}
	
	return dis;
}

//vector<int> spf(const vector<vector<n>> &g, int a, int u){
//	vector<int> dis(a, 1LL << 60);
//	vector<unsigned char> inq(a, 0);
//	queue<int> q;
//	q.push(u);
//	dis[u] = 0;
//	inq[u] = true;
//	
//	while(q.size()){
//		const int i = q.front();
//		q.pop();
//		
//		inq[i] = 0;
//		
//		for(const auto & [j, w] : g[i])
//			if(dis[i] + w < dis[j]){
//				dis[j] = dis[i] + w;
//				
//				if(!inq[j])
//					q.push(j),
//					inq[j] = 1;
//			}
//	}
//	
//	return dis;
//}

//vector<int> spf(const vector<vector<n>> &g, int a, int u){
//	vector<int> dis(a, 1LL << 60);
//	vector<unsigned char> inq(a, 0);
//	deque<int> q;
//	q.push_back(u);
//	dis[u] = 0;
//	inq[u] = true;
//	
//	int sum = 0;
//	
//	while(q.size()){
//		int i = q.front();
//		
//		while(dis[i] * q.size() > sum)
//			q.push_back(i),
//			q.pop_front(),
//			i = q.front();
//		
//		sum -= dis[i];
//		q.pop_front();
//		
//		inq[i] = 0;
//		
//		for(const auto & [j, w] : g[i])
//			if(dis[i] + w < dis[j]){
//				if(inq[j])
//					sum -= dis[j];
//				
//				dis[j] = dis[i] + w;
//				sum += dis[j];
//				
//				if(!inq[j]){
//					if(q.empty() || dis[q.front()] <= dis[j])
//						q.push_back(j);
//					else
//						q.push_front(j);
//					
//					inq[j] = 1;
//				}
//			}
//	}
//	
//	return dis;
//}

signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	#if 1
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	#endif
	
	int a, b, c, mx;
	cin >> a >> b >> a >> mx >> c;
	
	vector<int> stk(b + 1, -1);
	
	stk[0] = 0;
	
	auto to = [&](int lv, int num) -> int{
		if(lv < 2)
			return lv * a + num - 1;
		
		return (a << 1) + stk[lv - 2] + num - 1;
	};
	
	int N = a * (mx + 2);
	
	vector<vector<n>> g(N);
	
	auto add = [&](int u, int v, int w) -> void{
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	};
	
	for(int i = 1; i <= a; ++ i){
		int ls;
		cin >> ls;
		
		add(to(0, i), to(1, i), ls);
	}
	
	for(int i = 1; i <= b; ++ i){
		int ls;
		cin >> ls;
		
		stk[i] = stk[i - 1] + ls;
		
		for(int j = 1; j != ls; ++ j)
			add(to(i + 1, j), to(i + 1, j + 1), 0);
		
		for(int j = 1; j <= ls; ++ j){
			int l1, l2;
			cin >> l1 >> l2;
			
			add(to(1, l1), to(i + 1, j), l2);
		}
	}
	
	g.resize(N = (a << 1) + stk[b]);
	
//	for(auto &i : g)
//		sort(i.begin(), i.end(), [](const n &l1, const n &l2){return l1.w < l2.w;});
	
	vector<vector<int>> cache(N);
	
	while(c --){
		int l1, l2;
		cin >> l1 >> l2;
		
		if(l1 > l2)
			std::swap(l1, l2);
		
		if(cache[to(0, l1)].empty())
			cache[to(0, l1)] = spf(g, N, to(0, l1));
		
		cout << cache[to(0, l1)][to(0, l2)] << "\n";
	}
	
	return 0;
}
