#include<bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long; 

void run();

int main()
{
	freopen("subway.out", "w", stdout);
	freopen("subway.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	run();
	
	return 0;
} 

i64 potNo, wayN, staN, maxTro, planN;
i64 pointN;
vector<i64> constTime;
vector<vector<pair<i64, i64>>> Graph;
#ifdef DEBUG
vector<i64> fromP;
#endif

i64 shortestPath(i64 s, i64 t)
{
	// SPFA
	vector<i64> dist(pointN+1, 1e18);
	dist[s] = 0;
	
	vector<char> inq(pointN+1, 0);
	inq[s] = 1;
	
	queue<i32> que;
	que.push(s);
	
#ifdef DEBUG
fromP.resize(pointN+1);
#endif
	
	while(!que.empty())
	{
		
		i64 u = que.front();
		que.pop();
		inq[u] = 0;
		
		
		for(auto edg : Graph[u])
		{
			i64 v = edg.first;
			i64 val = edg.second;
			i64 nd = dist[u] + val;
			if(nd < dist[v])
			{
				dist[v] = nd;
				#ifdef DEBUG
//				fromP[v] = u;
//				cout << "to" << v << " " << dist[v];
				#endif
				if(!inq[v])
				{
					que.push(v);
					inq[v] = 1;
				}
			}
		} 
	}
	
	return dist[t];
}

void addEdge(i64 s, i64 t, i64 val)
{
	#ifdef DEBUG
//	cout << "addedge:" << s << " " << t << " " << val << endl;
	#endif
	Graph[s].push_back({t, val});
	Graph[t].push_back({s, val});
}

void run()
{
	cin >> potNo >> wayN >> staN >> maxTro >> planN;
	pointN = wayN + staN;
	Graph.resize(pointN + 1);
	
	constTime.resize(staN + 1);
	for(i32 i = 1; i <= staN; ++i)
	{
		cin >> constTime[i];
	}
	
	for(i32 lin = 1; lin <= wayN; ++lin)
	{
		i64 staTro;
		cin >> staTro;
		for(i32 stan = 1; stan <= staTro; stan++)
		{
			i32 staNo;
			cin >> staNo;
			i64 tim;
			cin >> tim;
			addEdge(lin + staN, staNo, tim);
		}
	}
	
	for(i32 pla = 1; pla <= planN; ++pla)
	{
		i32 stS, endS;
		cin >> stS >> endS;
		
		i64 ans = shortestPath(stS, endS);
		#ifdef DEBUG]
//		cout << "OnWay:" << ans << endl;
		#endif
		
		ans += constTime[stS] + constTime[endS];
		cout << ans << endl;
		
		#ifdef DEBUG
//		cout << "Path:" << endl;
//		i64 p = endS;
//		do
//		{
//			p = fromP[p];
//			cout << "Sta:" << p << endl;
//		}
//		while(p!= stS);
		#endif
	}
}
