#include<bits/stdc++.h>
using namespace std;
long long co,n,m,d,q,a,w[505],lp[500005],tot[500005],k[505],u[505][500010],t[505][500005],i,op,st,ed;
vector<long long>c[500005];
long long dfs(int x,long long tbtt){
	long long mn=4e18;
	int tt=0;
	if(x==ed)return mn;
	for(int i:c[x]){
		tt++;
		for(int j=1;j<=k[i];j++){
			if(j==x)continue;
			mn=min(mn,dfs(j,tbtt+t[i][lp[x][tt]]+t[i][j]));
		}
	}
	return mn;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	
	cin>>co>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>op>>t[i][j];
			c[op].push_back(i); 
			lp[op][++tot[op]]=j; 
			u[i][j]=op;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>st>>ed;
		cout<<dfs(st)+w[st]+w[ed]<<"\n";
	}
	return 0;
} 
