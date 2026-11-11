#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=5e5+5;
int a[N],cnt[M],l[M],in[M];
map<int,int> mp;
int c[M],vis[M];
void dfs(int x,int flag){
	if(a[x]==0)return ;
	in[a[x]]+=flag;
	if(mp[a[x]])return ;
	mp[a[x]]=1;
	x=l[a[x]];
	dfs(x+1,1);
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],l[a[i]]=i;
	for(int i=1;i<=n;i++){
		dfs(i,0);
		c[a[i]]++;
	}
	queue<int> s;
	for(int i=1;i<=m;i++){
		if(in[i]==0)s.push(i);
	}
	while(!s.empty()){
		int u=s.front();
		s.pop();
		int v=a[l[u]+1];
		if(v!=0){
			c[v]+=c[u];
			in[v]--;
			if(in[v]==0){
				s.push(v);
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i==m)cout<<c[i]; 
		else cout<<c[i]<<" ";
	}
	cout<<"\n";
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
