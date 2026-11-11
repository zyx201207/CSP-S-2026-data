#include<bits/stdc++.h>

using namespace std;
vector<vector<long long>> dis(600,vector<long long>(600,(long long)1e10));
int main()
{
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	cout<<c<<n<<m<<d<<q;
	int kou2zhan[m+1];
	for (int i = 1;i <= n;i++)cin>>kou2zhan[i];
	vector<vector<pair<int,int>>> l(n+10);

	for (int i  = 0;i < n;i++){
		vector<pair<long long,int>> new_node;
		int k;
		cin>>k;
		for (int j = 0;j < k;j++)
		{
			int t0,t1;
			cin>>t0>>t1;
			new_node.push_back({t1,t0});
		}
		for (int j = 0;j < k;j++)
			for (int k = j+1;j < k;j++)
				l[new_node[j].second].push_back({new_node[k].first + new_node[j].first,new_node[k].second});
		}


	//cout<<l[1][0].second<<l[1][0].first;
	for (int i = 1;i <= m;i++)
	{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		pq.push({kou2zhan[i],i});
		dis[i][i] =(long long) kou2zhan[i];

		while (!pq.empty())
		{
			pair<long long,int> cur = pq.top();
			pq.pop();
			if (dis[i][cur.second] != cur.first)continue;
			for (int j = 1;j < l[cur.second].size();j++)
			{
				cout<<cur.first + (long long) l[cur.second][j].first;
				if ((long long)cur.first + (long long)l[cur.second][j].first < dis[i][l[cur.second][j].second]){
				//if ((long long)1 < (long long) 1){
					pq.push({cur.first + ((long long) l[cur.second][j].first),l[cur.second][j].second});
					dis[cur.second][l[cur.second][j].second] = cur.first + (long long)l[cur.second][j].first;
				}
			}
		}

	}
	for (int i = 0;i < q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y];
	}

	//vector<vector<int>> ljb(m);


 }
