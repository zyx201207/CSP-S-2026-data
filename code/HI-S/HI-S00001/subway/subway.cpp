#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1000010],t[1010][1010],k[1000010],ans=2e9,vis[1000010];
void dfs(int x,int y,int sum,int f){
	if(x==y){
		ans=min(ans,sum+t[y][f]);
		return;
	}
	for(int i=1;i<=m;i++){
		bool flag=false;
		if(vis[i]) continue;
		if(t[i][f]) flag=true;
		if(flag){
			vis[i]=1;
			dfs(i,y,sum,f);
			vis[i]=0;
		}
		else{
			int minn=2e9,p=0;
			for(int j=1;j<=n;j++){
				if(((t[x][f]+t[x][j])<minn)&&t[i][j]&&t[x][j]){
					minn=t[x][f]+t[x][j];
					p=j;
				}
			}
//			cout<<minn<<"\n";
			if(p==0) continue;
			if(f==0){
				vis[i]=1;
				dfs(i,y,sum+t[x][p],p);
				vis[i]=0;
			}
			else{
				vis[i]=1;
				dfs(i,y,sum+t[x][f]+t[x][p],p);
				vis[i]=0;
			}
		}
	}
	
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			t[x][i]=y;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=2e9;
		dfs(x,y,0,0);
		cout<<ans+w[x]+w[y]<<"\n"<<"\n";
	}
	return 0;
}
//omg wonadaobufenfenle!!!!
