#include <bits/stdc++.h>
using namespace std;
long long c,n,m,k,q,x[1000005];
long long idx=1,ne[1000005],w[1000005];
string e[1000005];
map<string,long long> h;
map<string,long long> di;
map<string,long long> f;
priority_queue<pair<long long,string>,vector<pair<long long,string>>,greater<pair<long long,string>>> oo;
void dij(string t)
{
	
	di[t]=0;
	oo.push({0,t});
	while(!oo.empty())
	{
		string u=oo.top().second;
		cout<<u<<'\n';
		oo.pop();
		if(f[u])continue;
		f[u]=1;
		for(int i=h[t];i;i=ne[i])
		{
			string now=e[i];
			if(!f[now]&&di[u]+w[i]<di[now])
			{
				di[now]=di[u]+w[i];
				oo.push({di[now],now});
			}
		}
	}
}
void add(string a,string b,long long z)
{
	e[idx]=b;
	w[idx]=z;
	ne[idx]=h[a];
	h[a]=idx++;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>k>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>x[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long o;
		string cnt;
		cin>>o;
		for(int j=1;j<=o;j++)
		{
			string a;
			long long t;
			cin>>a>>t;
			add("y"+a,to_string(i)+"z"+a,t);//yÌü z¿Ú 
			add(to_string(i)+"z"+a,"y"+a,t);
			di["y"+a]=1e9;
			di[to_string(i)+"z"+a]=1e9;
			if(j==1)cnt=a;
			else
			{
				add(to_string(i)+"z"+a,to_string(i)+"z"+cnt,0);
				add(to_string(i)+"z"+cnt,to_string(i)+"z"+a,0);
				cnt=a;
			}
		}
	}
	for(int j=1;j<=q;j++)
	{
		long long u,v;
		cin>>u>>v;
		dij("y"+to_string(u));
		cout<<x[u]+x[v]+di["y"+to_string(v)]<<'\n';
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
*/
