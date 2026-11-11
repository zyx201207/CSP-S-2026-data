#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010],a[510][30],t[510][30],idx,h[510],vis[510];
map<int,vector<int> > mp;
int mn=INT_MAX;
struct ns{
	int to,nxt;
}e[1010];
void add(int x,int y){
	e[++idx].to=y;
	e[idx].nxt=h[x];
	h[x]=idx;
}
void dfs(int x,int now,int y,int ans,bool isin){
//	cout<<ans<<' ';
	if(now==y){
		mn=min(ans,mn);
		return ;
	}
	if(!isin){
		for(int i=mp[now].size()-1;i>=0;i--){
			//cout<<t[mp[now][i]][now]<<' ';
		//	if(ans==25) cout<<t[mp[now][i]][now]<<endl;
			dfs(x,now,y,ans+t[mp[now][i]][now],1);
		}
	}
	else{
		for(int i=h[x];i;i=e[i].nxt){
			int j=e[i].to;
			//cout<<x<<':'<<j<<' '<<ans<<endl;
			if(vis[j]) continue;
			for(int k=0;k<mp[j].size();k++){
			//	cout<<t[mp[j][k]][j]<<' ';
				vis[j]=1;
			//	cout<<ans+t[mp[j][k]][j]<<endl;
				dfs(x,j,y,ans+t[mp[j][k]][j],0);
				vis[j]=0;	
			}
			
		}		
	}
	return ;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
			cin>>t[i][j];
			mp[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++){
			if(!a[i][j]) continue;
			for(int k=j+1;k<=d;k++){
				if(!a[i][k]) continue;
				add(a[i][j],a[i][k]);
				add(a[i][k],a[i][j]);	
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dfs(x,x,y,w[x]+w[y],0);
		cout<<mn<<endl;
	}
	return 0;
}
