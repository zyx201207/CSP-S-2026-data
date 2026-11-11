#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int maxn=2e6+5;
int c,t,n,d;
long long a[maxn];
int minn;
int f[maxn];
bool b[maxn];
int cnt;
int ans;
int num;
void dfs(int u,int y,int t,vector<int> G[maxn]){
	if(u==y) ans=min(ans,t);
	for(auto v:G[u]){
		if(t>=f[v]&&b[v]==true) continue;
		f[v]=t;
		b[v]=true;
		dfs(v,y,t+1,G);
    }
}
void dfsk(int u,int y,int t,vector<int> G[maxn]){
	if(u==y)    if(ans==t) cnt++;
	for(auto v:G[u]){
		if(t>=f[v]&&b[v]==true) continue;
		f[v]=t;
		b[v]=true;
		dfs(v,y,t+1,G);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int p=1;p<=t;p++){
		cin>>n>>d;
		num=0;
		vector<int> G[maxn];
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(abs(a[i]-a[j])<=d){
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				cnt=0;
		        ans=maxn;
		        for(int k=1;k<=n;k++) b[k]=false;
		        for(int k=1;k<=n;k++) f[k]=maxn;
				dfs(i,j,0,G);
				dfsk(i,j,0,G);
				if(cnt==2) num++;
			}
		}
		cout<<num;
	}
}
