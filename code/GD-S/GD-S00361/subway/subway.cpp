#include<bits/stdc++.h>
using namespace std;
long long cost[505][505];
vector<pair<int,long long>> g[500005];
long long w[500005];
inline int read(){
	int x=0;
	char c=getchar();
	if(c<'0'||c>'9'){
		c=getchar();
	}
	if(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x;
}
void write(long long x){
	stack<char> st;
	while(x){
		st.push(x%10+'0');
		x/=10;
	}
	while(!st.empty()){
		putchar(st.top());
		st.pop();
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	memset(cost,0x3f,sizeof(cost));
	for(int i=1;i<=m;i++){
		w[i]=(long long)read();
	}
	for(int i=1;i<=n;i++){
		cost[i][i]=0;
		int k=read();
		write(i);
		for(int j=1;j<=k;j++){
			int a=read();
			int t=read();
			g[a].push_back({i,t}); 
		}
		putchar('\n');
	}
	for(int i=1;i<=m;i++){
		for(int u=0;u<g[i].size()-1;u++){
			for(int v=u+1;v<g[i].size();v++){
				int u1=g[i][u].first,v1=g[i][v].first;
				long long w1=g[i][u].second+g[i][v].second;
				cost[u1][v1]=cost[v1][u1]=min(w1,cost[u1][v1]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j||i==k||j==k)continue;
				if(cost[j][k]>cost[j][i]+cost[i][k]){
					cost[j][k]=cost[k][j]=cost[i][j]+cost[i][k]; 
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x=read(),y=read();
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(auto u:g[x]){
			for(auto v:g[y]){
				ans=min(ans,cost[u.first][v.first]+u.second+v.second);
			}
		}
		ans+=w[x];
		ans+=w[y];
		write(ans);
		putchar('\n');
	}
	return 0;
}
