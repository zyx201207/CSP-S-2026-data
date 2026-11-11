#include<bits/stdc++.h>
using namespace std;
int c,n,k,q,as;
int cities[1000005],vis[1000005],be_choosed[1000005],vis1[1000005],d[1000005];
vector<int> v[1000005];
void dff(int w)
{
	vis1[w]=1;
	for(auto nxt:v[w])
	{
		if(be_choosed[nxt]&&vis1[nxt]==0)
		{
			dff(nxt);
		}
	}
}
bool check()
{
	int sss=0;
	for(int i=1;i<=k;i++)
	{
		vis1[i]=0;
	}
	for(int i=1;i<=k;i++)
	{
		if(!vis1[i])
		{
			sss++;
			if(sss>2)return 0;
			dff(cities[i]);
		}
	}
	return sss<=2;
}
void f()
{
	if(!check())return ;
	for(int i=1;i<=n;i++)d[i]=1e9+114514;
	queue<int> q;
	for(int i=1;i<=k;i++)
	{
		q.push(cities[i]);
		d[cities[i]]=0;
	}
	while(q.size())
	{
		int w=q.front();
		q.pop();
		for(auto nxt:v[w])
		{
			if(d[w]+1<d[nxt])
			{
				d[nxt]=d[w]+1;
				q.push(nxt);
			}
		}
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,d[i]);
	}
	as=min(as,ans);
}
void dfs(int w)
{
	if(w>k)
	{
		f();
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			be_choosed[i]=1;
			cities[w]=i;
			vis[i]=1;
			dfs(w+1);
			be_choosed[i]=0;
			cities[w]=0;
			vis[i]=0;
		}
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int q,p;
		cin>>q>>p;
		v[q].push_back(p);
		v[p].push_back(q);
	}
	as=1e9+114514;
	dfs(1);
	cout<<as<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>q;
	while(q--)
	{
		solve();
	}
	return 0;
}
//Oct31==Dec25?
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

//finish at 
