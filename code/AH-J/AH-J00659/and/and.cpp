#include<bits/stdc++.h>
using namespace std;
bool g[200001];
int e[200001];
int x,y,maxn=INT_MIN;
void dfs(int a,int c){
	if(a==y){
		maxn=max(maxn,c);
		return ;
	}
	for(int i=1;i<=x;i++){
		if(!g[i]){
			g[i]=1;
			dfs(a+1,c&e[i]);
		}else{
			continue;
		}
		g[i]=0;
	}	
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>x>>y;
	for(int i=1;i<=x;i++){
		cin>>e[i];
	}
	for(int j=1;j<=x;j++){
		if(g[j]!=1){
			g[j]=1;
			dfs(1,e[j]);
		}else{
			dfs(1,e[j]);
		}
		g[j]=0;
	}
	cout<<maxn;
	return 0;
}
