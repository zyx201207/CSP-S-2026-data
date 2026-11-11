#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int c,n,m,d,q;//n 列车数 m 站台数  
int w[505];
int k[505];
int a[505][1005];//一 列车编号 二 地铁站编号 
int t[505][1005];//一 列车编号 二 地铁站编号 
int f[1005][1005];//f用于建立图 地铁可以看作边 边权值为在一个站台上站厅+从站厅下站台时间 一 二 地铁站编号 
long long ans;
int x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=1e9;
		}
	} 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}//对f进行操作 
	for(int ll=1;ll<=n;ll++){
		for(int i=1;i<=k[ll];i++){
			for(int j=1;j<=k[ll];j++){
				if(i==j) continue;
				f[a[ll][i]][a[ll][j]]=t[ll][i]+t[ll][j];
			}
		}
	}
	for(int l=1;l<=m;l++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=w[x]+w[y];
		ans+=f[x][y];
		cout<<ans<<endl;
	}
	return 0;
}
