#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+100;
int c,n,m,d,q;
int w[N];
int k[510];
int a[510][30000];
int T[510][30000];
void dfs(int x,const int &ed,int time,int type,int &ans,vector<bool>&vis){
	if(x==ed&&type==2){
		ans=min(ans,time);
		return ;
	}
	if(type==1){
		dfs(x,ed,time+w[x],2,ans,vis);
		return ;
	}
	for(int i=1;i<=k[x];i++){
		if(type==2){
			dfs(a[x][i],ed,time+T[x][i],3,ans,vis);
		}
		else if(type==3&&!vis[a[x][i]]){
			vis[a[x][i]]=1;
			dfs(a[x][i],ed,time+T[x][i],1,ans,vis);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdin);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>T[i][j]; 
		}
	}
	while(q--){
		int x,y;
		int ans=1e9;
		cin>>x>>y;
		vector<bool>vis(n+1,0); 
		vis[x]=1;
		dfs(x,y,0,1,ans,vis);
		cout<<ans<<'\n';
	}
	return 0;
}

