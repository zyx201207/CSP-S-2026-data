#include<bits/stdc++.h>
using namespace std;

int n,m,c,d,q,w[500005],sta,en,a,t,k;
bool dl[50005][505];
long long s[50005][505],ans;

void dfs(int x,int y,long long ansl){
	if(y==en){
		ans=min(ans,ansl+s[x][y]+w[en]);
		return;
	}
	for(int j=1;j<=n;j++){//换乘
		if(s[j][y]>0&&!dl[j][y]){
			dl[j][y]=1;
			dfs(j,y,ansl+s[j][y]+s[x][y]);
			dl[j][y]=0;
		}
	}
	for(int j=1;j<=m;j++){//坐车到下一个站
		if(s[x][j]>0&&!dl[x][j]){
			dl[x][j]=1;
			dfs(x,j,ansl);
			dl[x][j]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			s[i][a]=t;
		}
	} 
	
	for(int i=1;i<=q;i++){
		cin>>sta>>en;
		ans=1e18;
		for(int j=1;j<=n;j++){
			if(s[j][sta]>0){//起点可走线路 
				dl[j][sta]=1;
				dfs(j,sta,s[j][sta]+w[sta]);
				dl[j][sta]=0;
			}
		}
		cout<<ans<<endl; 
	}
} 
