#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+3;
int cid,T;
ll n,d,x[N],minn,minsum,ed;
void dfs(int p,int dep){
	if(p==ed){
		if(dep==minn)minsum++;
		if(dep<minn){
			minn=dep;
			minsum=1;
		}
	}
	if(dep>minn)return;
	for(int i=p+1;i<=n;i++){
		if((x[i]-x[p])>d)break;
		dfs(i,dep+1);
	}
}
bool check(int u,int v){
	minn=1e18,minsum=0,ed=v;
	dfs(u,0);
	return minsum==2;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=check(i,j);
	cout<<ans<<'\n'; 
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>cid>>T;
	while(T--)
		solve();
	return 0;
}
/*
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
