#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int n,m,a[maxn],vs,cnt,c[maxn],nxt[maxn],last[maxn],b[maxn],las[maxn],bs;
int vis[maxn];
bool app[maxn];
vector<int>g[maxn];
struct xx{
	int x,y;
};
stack<xx>st;
signed main(){
	
	freopen("card.in","r",stdin) , freopen("card.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	for(int i=n;i>0;i--)
	{
		nxt[i]=last[a[i]];
		last[a[i]]=i;
		//cout<<nxt[i]<<" ";
	}
	for(int i=n;i>0;i--)
	{
//		cout<<i<<" "<<vs<<" "<<vis[a[i]]<<'\n';
		if(!nxt[i])
		{
			st.push({a[i],i});
			vis[a[i]]++;
			vs++;
			g[a[i]].push_back(i);
		}
		else
		{
			//cout<<i<<' ';
			while(!st.empty())
			{
				int x=st.top().x , y=st.top().y;
				if(y<nxt[i]) 
				{
					vis[x]--;
					//cout<<x<<'-'<<y<<'='<<vis[x]<<" ";
					if(!vis[x])
					{
						vs--;
						g[x].push_back(i);
					}
					st.pop();
				}
				else break;
			}
			//cout<<'\n';
			st.push({a[i],i});
			vis[a[i]]++;
			if(vis[a[i]]==1) vs++ , g[a[i]].push_back(i);
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		if(g[i].size()%2==1) g[i].push_back(0);
		for(int j=0;j<g[i].size();j++)
		{
			if(j%2==1) c[i]+=g[i][j]-g[i][j-1];
		}
		cout<<-c[i]<<" ";
	}
	
	
	return 0;
}
/*1st
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int n,m,a[maxn],vs,b[maxn],cnt,c[maxn];
bool vis[maxn];
stack<int>st;
signed main(){
	
//	freopen("card.in","r",stdin) , freopen("card.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>0;i--)
	{
		if(!vis[a[i]])
		{
			st.push(a[i]);
			vis[a[i]]=1;
			vs++;
		}
		if(vs==m) break;
	}
	while(!st.empty())
	{
		b[++cnt]=st.top();
		st.pop();
	}
	for(int i=1;i<=n;i++)
	{
		c[b[i]]++;
	}
	
	
	return 0;
} 
*/
