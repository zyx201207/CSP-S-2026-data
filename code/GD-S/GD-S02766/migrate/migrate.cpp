#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
vector<vector<long long>> road;
long long solve(long long begin)
{
	vector<bool> used(n+1,false);
	vector<vector<long long>> father(n+1);
	vector<long long> dis(n+1,INT_MAX);
	for(int i = 1;i <= begin;i++)
	{
		used[i] = true;
	}
	dis[begin] = 0;
	for(auto t : road[begin])
	{
		if(used[t]) continue;
		dis[t] = 1;
		father[t].push_back(begin);
	}
	for(int i = begin+1;i <= n;i++)
	{
		long long mi = INT_MAX;
		long long w = -1;
		for(int j = begin+1;j <= n;j++)
		{
			if(used[j]) continue;
			if(dis[j] < mi)
			{
				mi = dis[j];
				w = j;
			}
		}
		if(w == -1) break;
		used[w] = true;
		for(auto a : road[w])
		{
			if(used[a]) continue;
			if(dis[w]+1 < dis[a])
			{
				father[a].clear();
				father[a].push_back(w);
				dis[a] = dis[w]+1;
			} 
			else if(dis[w]+1 == dis[a])
			{
				father[a].push_back(w);
			}
		}
	}
	long long ans = 0;
	for(auto v : father)
	{
		if(v.size() == 2) ans++;
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int T = 1;T <= t;T++)
	{
		cin >> n >> d;
		vector<long long>way(n+1);
		road.resize(n+1);
		for(int i = 1;i <= n;i++)
		{
			cin >> way[i];
			for(int j = i-1;j >= 1;j--)
			{
				if(way[i] - way[j] > d) break;
				road[i].push_back(j); 
				road[j].push_back(i);
			}
		}
		long long ans = 0;
		for(int i = 1;i <= n;i++)
		{
			ans += solve(i);
		}
		cout << ans << endl;
	}
	return 0;	
}
