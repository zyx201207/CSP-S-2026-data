#include<bits/stdc++.h>
using namespace std;
bool st;
const int N=505,M=1000005;
const long long MAX=1e17;
long long id,n,m,d,q,ans;
long long dis[N][N];
long long c[M][20],w[M];
int b[M][20],tot[M];
bool en;
void mini(long long &x,long long y){
	x=min(x,y);
}int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>id>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			int x,y;
			cin>>x>>y;
			tot[x]++;
			b[x][tot[x]]=i;
			c[x][tot[x]]=y;
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=MAX;
		}
	}for(int i=1;i<=m;i++){
		for(int j=1;j<=tot[i];j++){
			for(int k=j+1;k<=tot[i];k++){
				mini(dis[b[i][j]][b[i][k]],c[i][j]+c[i][k]);
				mini(dis[b[i][k]][b[i][j]],c[i][j]+c[i][k]);
			}
		}
	}for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				if(k==j||i==j) continue;
				mini(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}cout<<endl;
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=MAX;
		for(int i=1;i<=tot[x];i++){
			for(int j=1;j<=tot[y];j++){
				mini(ans,c[x][i]+c[y][j]+dis[b[x][i]][b[y][j]]);
			}
		}cout<<ans+w[x]+w[y]<<endl;
	}//cerr<<abs(&st-&en)*1.0/1024/1024;
	return 0;
}
