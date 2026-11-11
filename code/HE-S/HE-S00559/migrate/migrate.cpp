#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e6+1;
int n;
ll d,x[maxn];
int cnt;
void dfs(int u,int v,ll dis,ll want){
	if(dis>want) return;
	if(u==v){
		if(dis==want){
			cnt++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(u!=i&&abs(x[u]-x[i])<=d){
			dfs(i,v,dis+abs(x[u]-x[i]),want);
		}
	}
}
ll fun_cnt(int u,int v){
	ll dis=0;
	for(int i=u;i<=v;i++){
		int j=i;
		ll now_dis=0;
		while(j<v&&now_dis+x[j+1]-x[j]<=d){
			j++;
			now_dis+=x[j+1]-x[j];
		}
		i=j;
		dis+=now_dis;
	}
	cnt=0;
//	cout<<u<<"->"<<v<<" dis="<<dis<<" cnt=";
	dfs(u,v,0,dis);
//	cout<<cnt<<endl;
	return cnt;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int ans=0;
	for(int u=1;u<=n;u++){
		for(int v=1;v<=n;v++){
			if(fun_cnt(u,v)==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
} 
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		solve();
	}
    return 0;
}
/*
cnt dis
u->v dis=dis?
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

