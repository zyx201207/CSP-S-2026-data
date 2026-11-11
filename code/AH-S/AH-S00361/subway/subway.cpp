#include<bits/stdc++.h>
using namespace std;

struct station
{
	int st,t;
}stat[500010];

struct timeee
{
	int ttt,vis;
}timee[500010][510];

int c,n,m,d,q;
long long ans;
long long w[500010];
queue<int> qq;

int lprol(int x)
{
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(j == x && timee[j][i].vis != 0)
			{
				return i;
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> stat[j].st >> stat[j].t;
			timee[stat[j].st][i].ttt = stat[j].t;	
		}
		for(int j = 1;j < n;j++)
		{
			timee[stat[j].st][stat[j+1].st].vis = 1;
			timee[stat[j+1].st][stat[j].st].vis = 1;
		}
	}
	while(q--)
	{
		int s,tt;
		cin >> s >> tt;
		ans = timee[s][lprol(s)].ttt+timee[tt][lprol(tt)].ttt+w[s]+w[tt];
		qq.push(s);
		while(qq.size())
		{
			int i = qq.front();
			qq.pop();
			int mn = 1e8,pos = -1;
			for(int j = 1;j <= n;j++)
			{
				if(timee[i][j].vis == 1 && mn > timee[j][lprol(j)].ttt)
				{
					mn = timee[j][lprol(j)].ttt;
					pos = j;
				}
			}
			timee[i][pos].vis++;
			qq.push(pos);
			if(lprol(i) != lprol(pos))
			{
				ans += timee[i][lprol(i)].ttt+timee[pos][lprol(pos)].ttt;
			}
		}
		cout << ans << endl;	
	}
	return 0; 
}
