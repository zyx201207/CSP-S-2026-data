#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,ans=1e18;
ll w[500050];
ll mp[5005][5005];
bool vis[5005][5005];

ll k;
ll x,y;
void dfs(ll a,ll t){
	if(a==y){
		ans=min(ans,t);
		return;
	}
	for(int i=1;i<=d;i++){
		if(mp[i][a]!=0&&vis[i][a]==false){
			vis[a][i]=true;
			dfs(i,t+mp[a][i]);
			vis[a][i]=false;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){		
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			mp[k][x]=y;
			mp[x][k]=y;
		} 
	} 
	for(ll i=1;i<=q;i++){
		cin>>x>>y;
		dfs(x,0);
		cout<<ans<<endl;
		ans=1e18;
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
