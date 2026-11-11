#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,a[1000005],dd[1000005],ans,vis[1000005],d[1000005],f[1000005];
vector<int>v[1000005];
void dfss(int x,int fa){
	vis[x]=1;
	for(auto y:v[x]){
		if(y!=fa&&dd[y]){
			dfss(y,x);
		}
	}
}
void dfsss(int x,int fa){
	f[x]=f[fa]+1;
	for(auto y:v[x]){
		if(y!=fa){
			dfsss(y,x);
		}
	}
}
bool check(){
	int cnt=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=k;i++){
		if(!vis[a[i]]){
			dfss(a[i],0);
			cnt++;
		}
		if(cnt>2) return 0;
	}
	return 1;
}
void dfs(int x,int s){
	if(s==k+1){
		if(check()){
			memset(d,0x3f,sizeof(d));
			for(int i=1;i<=k;i++){
				f[0]=-1;
				dfsss(a[i],0);
				for(int j=1;j<=n;j++){
					d[j]=min(f[j],d[j]);
				}
			}
			int mx=0;
			for(int i=1;i<=n;i++){
				mx=max(mx,d[i]);
			}
			ans=min(ans,mx);
		}
		return;
	}
	if(x>n) return;
	dfs(x+1,s);
	dd[x]=1;
	a[s]=x;
	dfs(x+1,s+1);
	dd[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ans=1e9;
		dfs(1,1);
		cout<<ans<<endl;
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
