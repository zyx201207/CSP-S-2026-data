#include<bits/stdc++.h>
using namespace std;
struct qq{
	int x;
	int y;
};
int c,n,m,cc,k;
int a[50005];
vector<qq> g[50005];
int d[500005];
int v[500005];

void ss(int st)
{
	for(int i = 1;i <= m;++i)
	{
		v[i]=0;
		d[i]=1000000000;
	}
	queue<int> q;
	q.push(st);
	v[st]=1;
	d[st]=0;
	while(q.size()!=0)
	{
		int t = q.front();
		q.pop();
		v[t]=0;
		
		for(int i = 1;i < g[t].size();++i)
		{
			int w =g[t][0].y;
			int o = g[t][i].x;
			int p = g[t][i].y;
			if(d[o]>d[t]+p+w)
			{
				d[o]=d[t]+p+w;
				
				if(v[o]==0)
				{	v[o]=1;
					q.push(o);
					
				}
			}
		}
	
	}
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> cc >> k;
	for(int i = 1;i <= m;++i)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;++i)
	{
		int q;
		cin >> q;
		for(int j = 1;j <= q;++j)
		{
			int o,p;
			cin >> o >> p; 
			g[i].push_back({o,p});
		}
	}
	for(int i = 0;i < k;++i)
	{
		int o,p;
		cin >> o >> p;
		int s = a[o]+a[p];
		memset(d,0,sizeof d);
		memset(v,0,sizeof v);
		ss(o);

		s+=d[p];
		cout << s << endl;
		
	}
	
	return 0;
}
