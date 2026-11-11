#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;

int n , m , c , d , q , T , g;
int w[N] , ans;
int len[N];
int s , e , minn = INF;
bool v[N];
bool v1[N];
int temp[N];

vector < pair<int , int> > vec[N];
vector < pair<int , int> > line[N];
vector <int> vc[N];
vector <int> vl[N];

void dfs(int x , int cost)
{
	if(x == e)
	{
		minn = min(minn , cost);
	}
	if(cost > minn)
	{
		return;
	}
	for(int i = 0 ; i < vec[x].size() ; i ++)
	{
		int xx = vec[x][i].first;
		if(!v[xx])
		{
			v[xx] = 1;
			dfs(xx , cost + vec[x][i].second);
			v[xx] = 0;
		}
		
	}
}

int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin>>c>>n>>m>>d>>g;
	for(int i = 1 ; i <= m ; i ++)
	{
		cin>>w[i];
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		cin>>len[i];
		for(int j = 1 ; j <= len[i] ; j ++)
		{
			int x , y;
			cin>>x>>y;
			T = y;
			line[i].push_back({x , y});
			vc[x].push_back(i);
		}
	}
	if(c >= 7 && c <= 11)
	{
		
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 0 ; j < len[i] ; j ++)
			{
				for(int k = 0 ; k < len[i] ; k ++)
				{
					if(k != j)
					{
						vec[line[i][j].first].push_back({line[i][k].first , line[i][j].second + line[i][k].second});
					}
					
				}
				
			}
		}
		for(int i = 1 ; i <= g ; i ++)
		{
			cin>>s>>e;
			dfs(s , 0);
			cout<<minn + w[s] + w[e]<<endl;
			minn = INF;
		}
		return 0;
	}
	if(c >= 12 && c <= 19)
	{
		for(int i = 1 ; i <= m ; i ++)
		{
			if(vc[i].size() > 1)
			{
				for(int j = 0 ; j < vc[i].size() ; j ++)
				{
					for(int k = 0 ; k < vc[i].size() ; k ++)
					{
						if(j != k)
						{
							vl[vc[i][j]].push_back(vc[i][k]);
							vl[vc[i][k]].push_back(vc[i][j]);
						}
					}
				}
			}
		}
		for(int i = 1 ; i <= g ; i ++)
		{
			cin>>s>>e;
			memset(temp , 0 , sizeof(temp));
			
			for(int j = 0 ; j < vc[e].size() ; j ++)
			{
				temp[vc[e][j]] = 1;
			}
			queue < pair<int , int> > q;
			for(int j = 0 ; j < vc[s].size() ; j ++)
			{
				q.push({vc[s][j] , 0});
			}
			memset(v1 , 0 , sizeof(v1));
			while(!q.empty())
			{
				pair<int , int> top = q.front();
				q.pop();
				if(temp[top.first])
				{
					cout<<2 * (top.second + 1) * T + w[s] + w[e]<<endl;
					break;
				}
				for(int j = 0 ; j < vl[top.first].size() ; j ++)
				{
					int t = vl[top.first][j];
					if(!v1[t])
					{
						v1[t] = 1;
						q.push({t , top.second + 1});
					}
				}
			}
		}
	}
		
	
}
