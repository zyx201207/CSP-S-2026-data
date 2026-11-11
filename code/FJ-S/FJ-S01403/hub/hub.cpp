#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

const int MAXN = 4e3+5;
vector<int> vmp[MAXN];
bool fa[MAXN][MAXN] = {0},fh[MAXN] = {0};
int size[MAXN] = {0};

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

void dfs(int x,int fa)
{
	size[x] = 1;
	for(int i = 0;i < vmp[x].size();i++)
	{
		if(vmp[x][i] == fa) continue;
		dfs(vmp[x][i],i);
		size[x] += size[vmp[x][i]];
	}
	return ;
}

int main() 
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c = read(),t = read();
	while(t--)
	{
		int n = read(),ck = read();
		for(int i = 0;i < n-1;i++)
		{
			int u = read()-1,v = read()-1;
			vmp[u].push_back(v);
			vmp[v].push_back(u);
		}
		
		queue<int> qf;
		qf.push(0);
		while(qf.size())
		{
			int nf = qf.front();
			qf.pop();
			for(int i = 0;i < vmp[nf].size();i++)
			{
				if(fa[nf][vmp[nf][i]]) continue;
				for(int j = 0;j < n;j++)
					fa[vmp[nf][i]][j] = fa[nf][j];
				fa[vmp[nf][i]][nf] = 1;
				qf.push(vmp[nf][i]);
			}
		}
		
		dfs(0,-1);
		
		int min_ = INT_MAX;
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				if(i == j) continue;
				for(int k = 0;k < n;k++) fh[k] = 0;
				fh[i] = fh[j] = 1;
				priority_queue<pair<int,int> > nq;
				
				for(int k = 0;k < vmp[i].size();k++)
				{
					if(fh[vmp[i][k]]) continue;
					if(fa[vmp[i][k]][i])
					{
						if(fa[j][vmp[i][k]]) nq.push(make_pair(size[vmp[i][k]]-size[j],vmp[i][k]));
						else nq.push(make_pair(size[vmp[i][k]],vmp[i][k]));
					}
					else
					{
						if(fa[j][vmp[i][k]]) nq.push(make_pair(size[vmp[i][k]]-size[j]-size[i],vmp[i][k]));
						else nq.push(make_pair(size[vmp[i][k]]-size[i],vmp[i][k]));
					}
				}
				for(int k = 0;k < vmp[j].size();k++)
				{
					if(fh[vmp[j][k]]) continue;
					if(fa[vmp[j][k]][j])
					{
						if(fa[i][vmp[j][k]]) nq.push(make_pair(size[vmp[j][k]]-size[i],vmp[j][k]));
						else nq.push(make_pair(size[vmp[j][k]],vmp[j][k]));
					}
					else
					{
						if(fa[i][vmp[j][k]]) nq.push(make_pair(size[vmp[j][k]]-size[i]-size[j],vmp[j][k]));
						else nq.push(make_pair(size[vmp[j][k]]-size[j],vmp[j][k]));
					}
				}
				
				int cs = nq.size();
				
				int lk = ck-2;
				while(lk)
				{
					int nqt = nq.top().se;
					nq.pop();
					fh[nqt] = 1;
					lk--;
					for(int k = 0;k < vmp[nqt].size();k++)
					{
						if(fh[vmp[nqt][k]]) continue;
						nq.push(make_pair(size[vmp[nqt][k]]-size[nqt],vmp[i][k]));
						//... 
					}
				}
				
				//...
				
				min_ = min(min_,n/cs-(ck-2)/cs);
				
				while(nq.size()) nq.pop();
			}
		}
		
		cout<<min_<<endl;
		
		for(int i = 0;i < n;i++)
		{
			vmp[i].clear();
			for(int j = 0;j < n;j++)
				fa[i][j] = 0;
		}
	}
	
	return 0;
}

/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
