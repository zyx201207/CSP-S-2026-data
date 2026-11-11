#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

const int MAXN = 505,MAXM = 5e5+5,MAXD = 25;
const ll INF = 1e15;
ll w[MAXM] = {0};
vector<pair<int,ll> > sta[MAXM];
ll mp[MAXN][MAXN] = {0};

ll read()
{
	ll res = 0;
	bool f = 0;
	char tc = getchar();
	while(tc < '0' || tc > '9')
	{
		if(tc == '-') f = 1;
		tc = getchar();
	}
	while(tc >= '0' && tc <= '9')
	{
		res = (res<<1)+(res<<3)+(tc^48);
		tc = getchar();
	}
	return f?-res:res;
}

int main() 
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c = read(),n = read(),m = read(),d = read(),q = read();
	for(int i = 0;i < m;i++) w[i] = read();
	for(int i = 0;i < n;i++)
	{
		int k = read();
		for(int j = 0;j < k;j++)
		{
			int a = read()-1;
			ll t = read();
			sta[a].push_back(make_pair(i,t));
		}
	}
	
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			if(i == j) mp[i][j] = 0;
			else mp[i][j] = INF;
		}
	}
	
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < sta[i].size();j++)
		{
			for(int k = 0;k < sta[i].size();k++)
			{
				int u = sta[i][j].fi,v = sta[i][k].fi;
				ll tu = sta[i][j].se,tv = sta[i][k].se;
				if(mp[u][v] > tu+tv)
					mp[u][v] = tu+tv;
			}
		}
	}
	
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			for(int k = 0;k < n;k++)
				if(mp[j][k] > mp[j][i]+mp[i][k])
					mp[j][k] = mp[j][i]+mp[i][k];
	
	/*
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
			cout<<mp[i][j]<<" ";
		cout<<endl;
	}
	*/
	
	for(int i = 0;i < q;i++)
	{
		int x = read()-1,y = read()-1;
		ll min_ = INF;
		for(int j = 0;j < sta[x].size();j++)
		{
			for(int k = 0;k < sta[y].size();k++)
			{
				if(min_ > w[x]+w[y]+sta[x][j].se+sta[y][k].se+mp[sta[x][j].fi][sta[y][k].fi])
					min_ = w[x]+w[y]+sta[x][j].se+sta[y][k].se+mp[sta[x][j].fi][sta[y][k].fi];
				//cout<<w[x]<<" "<<w[y]<<" "<<sta[x][j].se<<" "<<sta[y][k].se<<" "<<mp[sta[x][j].fi][sta[y][k].fi]<<endl;
				//cout<<x<<" "<<y<<" "<<j<<" "<<k<<" "<<sta[x][j].fi<<" "<<sta[y][k].fi<<endl;
			}
		}
		printf("%lld\n",min_);
	}
	
	
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
