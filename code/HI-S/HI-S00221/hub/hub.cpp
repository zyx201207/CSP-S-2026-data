#include<bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long; 

void run();

int main()
{
	freopen("hub.out", "w", stdout);
	freopen("hub.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	run();
	
	return 0;
} 

i64 potNo, tstN, citN, hubN;
vector<vector<i64>> Graph;
vector<i64> leaves;

void addEdge(i64 s, i64 t)
{
	Graph[s].push_back(t);
	Graph[t].push_back(s);
}

bool check(u32 dist)
{
	
}

void test()
{
	cin >> citN >> hubN;
	Graph.resize(citN+1);
	for(i32 i = 1; i < citN; ++i)
	{
		i32 u, v;
		cin >> u >> v;
		addEdge(u, v);
	}
	
	if(citN == hubN)
	{
		cout << 0 << endl;
		return;
	}
	if(citN <= 3)
	{
		cout << 1 << endl;
		return;
	}
	
	for(i32 i = 1; i <= citN; ++i)
	{
		if(Graph[i].size() == 1)
		{
			leaves.push_back(i);
		}
	}
	
	if(citN == 4)
	{
		if(hubN >= 2)
		{
			cout << 1 << endl;
			return;
		}
		cout << citN - leaves.size();
	}
	
	if(citN == 5)
	{
		if(hubN >= 2)
		{
			cout << 1 << endl;
			return;
		}
		if(leaves.size() <= 3)
		{
			cout << 2 << return;
		}
		cout << 1 << return;
	}
	
	i32 l = 0, r = 1e5;
	while(l <= r)
	{
		i64 mid = l + (r-l)/2;
		if(check(mid))
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << r << endl;
}

void run()
{
	cin >> potNo, tstN;
	for(i32 i = 1; i <= tstN; ++i)
	{
		Graph.clear();
		leaves.clear();
		test();
	}
}
