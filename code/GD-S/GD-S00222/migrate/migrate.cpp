#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6+5;
int a[MAXN];
int node[MAXN];
int m[MAXN];
int c,t;
int n,d;
int cnt;
void dfs(int u,int depth){
	if((a[u+1]-a[u])>d) return ;
	if(m[u]>depth){
		m[u] = depth;
		node[u] = 1;
	}else if(m[u] == depth){
		node[u]++;
	}
	if(u == n) return ;
	for(int i = u;i<=n;i++){
		if((a[i]-a[u])>=d){
			dfs(i,depth+1);
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out ","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++)
			cin>>a[i];
		dfs(1,0);
		int cnt = 0;
		for(int i = 1;i<=n;i++){
			if(node[i] == 2) cnt++;
		}
		memset(node,0,sizeof(node));
		for(int i = 1;i<=n;i++)
			m[i] = 0x3f3f3f3f;
		cout<<cnt<<endl;
	}
	return 0;
}
