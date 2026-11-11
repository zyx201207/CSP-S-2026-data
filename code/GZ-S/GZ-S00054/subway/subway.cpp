//GZ-S00054 张世铠 贵阳市白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[200005];
ll k[505];
ll a[505][200005];
ll st,ed;
ll minn=LLONG_MAX;
ll c,n,m,d,p;
bool vis[200005];
void dfs(ll n,ll sum){
	if(n==ed){
		minn=min(minn,sum);
		return;
	}
	for(int i=1;i<=m;i++){
		if(!vis[i] && a[n][i]){
			vis[i]=1;
			dfs(i,sum+a[n][i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		ll pa,pt;
		for(int j=1;j<=k[i];j++){
			int pa,pt;
			cin>>pa>>pt;
			a[i][pa]=pt;
		}
	}
	for(int i=1;i<=p;i++){
		cin>>st>>ed;
		minn=LLONG_MAX;
		dfs(st,w[st]);
		cout<<minn+w[ed]<<endl;
	}
	return 0;
}
