#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, question;
int ditiekou[500005];
vector<pair<int, int>> e[500005];
vector<int> jin;
vector<int> chu;
map<int, int> ma;//DIJIGE
map<int, int> bian;
bool flag[500005];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

map<pair<int, int>, long long> mp;
long long dist[500005];

void dijkstra(int start)
{
	memset(dist, 0x3f, sizeof(dist));
	memset(flag, 0, sizeof(flag));
	while(!q.empty())
	{
		q.pop();
	}
	q.push({0, start});
	dist[start] = 0;
	while(!q.empty())
	{
		auto a = q.top();
		int a1 = a.second;
		int b1 = a.first;
		q.pop();
		if(flag[a1]) continue;
		flag[a1] = true;
		for(auto x:e[a1])
		{
			if(dist[x.first]>dist[a1]+x.second)
			{
				dist[x.first] = dist[a1]+x.second;
				q.push({dist[x.first], x.first});
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		mp[{start, i}] = min(dist[i], mp[{start, i}]);
		//cout << start << " "<< i<<" "<<mp[{start, i}]<<'\n';
	}
	return;
}

int main ()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> question;
	for(int i = 1;i <= m;i++)
	{
		cin >> ditiekou[i];
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			mp[{i, j}] = 0X3f3f3f3f;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin>> k;
		jin.clear();
		chu.clear();
		ma.clear();
		int pos = 0;
		while(pos < k)
		{
			int w;
			int v;
			cin >> w >> v;
			jin.push_back(w);
			chu.push_back(v);
			ma[w] = pos;
			pos++;
		}
		for(int j = 0;j < jin.size();j++)
		{
			for(int out:jin)
			{
				if(jin[j]!=out)
				{
					bool flagg = false;
					for(int z = 0;z < e[jin[j]].size();z++)
					{
						auto z1 = e[jin[j]][z];
						if(z1.first == out)
						{
							flagg = true;
							//e[jin[j]][z].second = min(e[jin[j][z]].second, chu[j]+chu[ma[out]]);
							if(chu[j]+chu[ma[out]]<e[jin[j]][z].second)
							{
								e[jin[j]][z] = {out, chu[j]+chu[ma[out]]};
							}
						}
					}
					if(!flagg)e[jin[j]].push_back({out, chu[j]+chu[ma[out]]});
					//cout << jin[j]<<" "<< out << " "<< chu[j]<<" "<<chu[ma[out]]<< '\n';
				}
			}
		}
	}
	/*for(int i = 1;i <= m;i++)
	{
		for(auto x1:e[i])
		{
			cout << x1.first << " ";
		}
		cout << '\n';
	}*/
	for(int i = 1;i <= m;i++)
	{
		dijkstra(i);
	}
	for(int i = 1;i <= question;i++)
	{
		int l, r;
		cin >> l >> r;
		//
		
		cout << ditiekou[l]+mp[{l, r}]+ditiekou[r]<<'\n';
	}
	return 0;
}
/*0 2 5 20 2
 
4 1 9 2 5 

3 1 5 2 7 4 6 

3 2 3 3 4 5 7 

1 3 

1 2
*/
