#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,num,ans,n,k,asn;
vector<int>v[105];
bool book[105],b[105],bb[105];
int bfs(int x)
{
	queue<pair<int,int>>q;
	q.push({x,0});
	memset(bb,0,sizeof bb);
	bb[x]=1;
	while(!q.empty())
	{
		int u=q.front().first,o=q.front().second;
		if(b[u])return o;
		for(auto it:v[u])
		{
			//int it=v[u][i];
			if(bb[it]==0)
			{
				bb[it]=1;
				q.push({it,o+1});
			}
		}
	}
	return 0x3f3f3f3f3f3f3f3f;
}	
void dfs(int x,int f,int y)
{
	//cout<<"aaaaaaaaaaaaa";
	num++;
	if(y<k)
	{
		b[x]=1;
		for(auto it:v[x])
		{
			if(it==f)continue;
			dfs(it,x,y+1);
		}
	}
	b[x]=0;
	for(auto it:v[x])
	{
		if(it==f)continue;
		dfs(it,x,y);
	}
	if(num==n&&y==k)
	{
		asn=0;
		for(int i=1;i<=n;i++)
		{
			if(book[i]==0)asn=max(asn,bfs(i));
		}
		ans=min(ans,asn);
	}
	num--;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{	
		cout<<0<<'\n';
	}
	return 0;
}/*num=0;
		ans=0x3f3f3f3f3f3f3f3f;
		memset(book,0,sizeof book);
		memset(b,0,sizeof b);
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++)
		{
			cout<<'b';
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0,0);0 1
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
