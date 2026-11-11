#include<bits/stdc++.h> 
using namespace std;
long long c,d,n,m,q;
long long w[100005];
long long k[100005],a[5005][5005],t[5005][5005];
long long x,y;
int vis[100005];
long long zt[1005][1005];
long long ans;
void dfs(int wz,int ti){
	if(wz==y){
		if(ans>ti)ans=ti;
		return ;
	}
	for(int i=1;i<=m;i++){
		if(zt[wz][i]>0&&vis[i]!=1){
			vis[i]=1;
			dfs(i,ti+zt[wz][i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<j;l++){
				if(zt[a[i][j]][a[i][l]]>0){
					zt[a[i][j]][a[i][l]]=min(zt[a[i][j]][a[i][l]],t[i][a[i][j]]+t[i][a[i][l]]);
					zt[a[i][l]][a[i][j]]=min(zt[a[i][l]][a[i][j]],t[i][a[i][j]]+t[i][a[i][l]]);
				}
				zt[a[i][j]][a[i][l]]=t[i][j]+t[i][l];
				zt[a[i][l]][a[i][j]]=t[i][j]+t[i][l];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=INT_MAX;
		vis[x]=1;
		dfs(x,w[x]+w[y]);
		vis[x]=0;
		cout<<ans<<endl;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
