#include<bits/stdc++.h>
using namespace std;
int c,n,d,x[15],vis[5005],f[5005];
int bfs(int uu,int v){
	int ans=0,suo=0;
	queue<pair<int,int> > q;
	q.push({uu,1});
	f[uu]=1;
	while(!q.empty()){
		int u=q.front().first,s=q.front().second;
		if(u==v||s==suo) break;
		q.pop();
		for(int i=v;i>=u+1;i--){
			if(abs(x[u]-x[i])<=d){
				if(!vis[i]&&!suo) q.push({i,s+1});
				if(i==v){
					suo=s+1;
				}
				f[i]+=f[u];
				vis[i]=1;
			}
		}
	}
//	cout<<f[1]<<' '<<f[2]<<' '<<f[3]<<' '<<f[4]<<'\n';
	return f[v];
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+1+n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			memset(vis,0,sizeof vis);
			memset(f,0,sizeof f);
			vis[i]=vis[j]=1;
			int f=bfs(i,j);
//			cout<<i<<' '<<j<<' '<<f<<'\n';
			if(f==2){
				cnt++;
			}
		}
	}
	cout<<cnt<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t=1;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
