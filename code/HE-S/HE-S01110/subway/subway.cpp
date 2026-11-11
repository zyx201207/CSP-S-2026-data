#include<bits/stdc++.h>
using namespace std;
struct aa
{
	long long a;
	long long b;
	int id;
	bool operator < (const aa &A)const
	{
		return A.b < b;
	}
}o,y[500005][25];
long long n,m,d,p,a,b,c1,c2,ii,yi[500005],z[1005][1005],in[1005][1005],out[1005][1005],v[500005],xi[500005],zi[500005];
vector<aa> x[500005];
priority_queue<aa> q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> ii >> m >> n >> d >> p;
	for(int i = 1;i <= n;i++)
	{
		cin >> zi[i];
	}
	for(int i = 1;i <= m;i++)
	{
		cin >> xi[i];
		cin >> a >> c1;
		yi[a]++;
		y[a][yi[a]] = {c1,0,i};
		for(int j = 2;j <= xi[i];j++)
		{
			cin >> b >> c2;
			x[a].push_back({b,c1+c2,i});
			x[b].push_back({a,c1+c2,i});
			yi[b]++;
			y[b][yi[b]] = {c2,0,i};
			a = b;
			c1 = c2;
		}
	}
	for(int k = 1;k <= n;k++)
	{
		while(!q.empty())
		{
			q.pop();
		}
		for(int i = 1;i <= n;i++)
		{
			z[k][i] = LLONG_MAX;
			v[i] = 0;
		}
		z[k][k] = 0;
		q.push({k,0,0});
		while(!q.empty())
		{
			o = q.top();
			q.pop();
			if(v[o.a] == 1)
			{
				continue;
			}
			v[o.a] = 1;
//			cout << o.a << ' ';
			for(int i = 0;i < x[o.a].size();i++)
			{
				if(z[k][x[o.a][i].a] > z[k][o.a]+x[o.a][i].b)
				{
					z[k][x[o.a][i].a] = z[k][o.a]+x[o.a][i].b;
					in[k][x[o.a][i].a] = in[k][o.a];
					if(o.a == k)
					{
						in[k][x[o.a][i].a] = x[o.a][i].id;
					}
					out[k][x[o.a][i].a] = x[o.a][i].id;
					q.push({x[o.a][i].a,z[k][x[o.a][i].a],0});
				}
			}
		}
	}
	while(p--)
	{
		cin >> a >> b;
		for(int i = 1;i <= yi[a];i++)
		{
			if(y[a][i].id == in[a][b])
			{
				c1 = y[a][i].a;
				break;
			}
		}
		for(int i = 1;i <= yi[b];i++)
		{
			if(y[b][i].id == out[a][b])
			{
				c2 = y[b][i].a;
				break;
			}
		}
		cout << z[a][b]+zi[a]+zi[b]-c1-c2 << '\n';
	}
	return 0;
}
