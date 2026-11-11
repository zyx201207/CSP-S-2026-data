#include<bits/stdc++.h>
using namespace std;
const int N=6e5+10;
long long c,n,m,d,q,w[N],k[1000],ans=0,vis[N],lj=0; 
long long x,y;
vector<long long> a[1000],t[1000];
vector<long long> ww[N];
void dfs(long long step,long long x){
	if(step==y){
		return;
	}
	for(long long eee:ww[step]){
		x=eee;
		long long jj=0;
		for(long long i=0;i<a[x].size();i++)
			if(a[x][i]==step)jj=t[x][i];
		for(long long i=0;i<a[x].size();i++){
			if(vis[a[x][i]]==0||vis[step]+jj+t[x][i]<vis[a[x][i]]){
				vis[a[x][i]]=vis[step]+jj+t[x][i];
				dfs(a[x][i],0);
			}	
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			ww[x].push_back(i);
		}
	}
	
	while(q--){
		cin>>x>>y;
		vis[x]=w[x];
		if(x==y)cout<<0<<'\n';
		else
		dfs(x,0);
		cout<<vis[y]+w[y]<<'\n';
		for(int i=1;i<=m;i++){
			vis[i]=0;
		}
	}
	return 0;
}
