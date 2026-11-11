#include <bits/stdc++.h>
using namespace std;
const int N=1e3+1;
int c,n,m,d,q,w[N],vis[N][N],min1=INT_MAX,k[N],t[N][N];
int dfs1(int x,int y){
	int q=0,sum=INT_MAX;
	for(int i=1;i<=n;i++){
		if(t[i][x]!=0 && t[i][y]!=0 && sum>t[i][x]+t[i][y]){
			q=i;
			sum=t[i][x]+t[i][y];
		}
	}
	return q;
}
int dfs(int x){
	int min1=INT_MAX,q1=0;
	for(int i=1;i<=n;i++){
		if(t[i][x]<min1) min1=t[i][x],q1=i;
	}
	return q1;
}
bool dfs3(int x){
	if((vis[x][1]==1 && vis[x][2]==1) || (vis[x][1]==1 && vis[x][3]==1) || (vis[x][2]==1 && vis[x][3]==1)){
		return true;
	}
	return false; 
}
int dfs2(int x){
	for(int i=1;i<=k[x];i++){
		if(dfs3(i)==true){
			return i;
		}
	}
	return 0;
}
int dfs4(int x,int y){
	for(int i=1;i<=n;i++){
		if(i!=y){
			if(vis[i][x]==1) return i;
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			int q,w;
			cin >> q >> w;
			t[i][q]=w;
			vis[q][i]=1;
		}
	}
	if(n<=3){
		while(q--){
			int ans=0;
			int x,y;
			cin >> x >> y;
			int q1=dfs1(x,y);
			if(q1>0) cout << w[x]+t[q1][x]+t[q1][y]+w[y] << "\n";
			else{
				int q2=dfs(x),x2=x,sum=0;
				ans+=w[x]+w[y];
				while(x2!=y){
					if(sum==2) break;
					ans+=t[q2][x2];
					x2=dfs2(q2);
					ans+=t[q2][x2];
					q2=dfs4(x2,q2);
					sum++;
				}
				cout << ans << "\n";
			}
		}
	}
	return 0;
}

