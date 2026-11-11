#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,tt[510][510];//厅 to j号线的台 
//测试号，线路数
//站数、每个站最多被几条线路经过
//计划数。
long long w[510],k[510];
//地铁口走到站厅需要的时间
long long a[510][510],t[510][510];
//第i 条线路经过的第j个地铁站
//该地铁站的站厅走到第i条线路的站台需要的时间。
vector<int> kk[100010]; //i被哪条线连过
long long f[510][510]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i ++){
		cin>>w[i];
	}
	for(int i = 1;i <= 500;i ++){
		for(int j = 1;j <= 500;j ++){
			f[i][j]=1e9; 
		}
	}
	for(int i = 1;i <= n;i ++){
		cin>>k[i];
		for(int j = 1;j <= k[i];j ++){
			cin>>a[i][j]>>t[i][j];
			kk[a[i][j]].push_back(i);
			tt[a[i][j]][i]=t[i][j];
		} 
	}
	for(int i = 1;i <= m;i ++){
		for(int j = 0;j < kk[i].size();j ++){
			for(int k = 0;k < kk[i].size();k ++){
				if(j ==k) continue;
				long long pp=kk[i][j],qq=kk[i][k];
				f[pp][qq]=min(f[pp][qq],tt[i][pp]+tt[i][qq]);
			}
		}
	}
	for(int k = 1;k <= n;k ++){
		for(int l = 1;l <= n;l ++){
			for(int r = 1;r <= n;r ++){
				f[l][r]=min(f[l][k]+f[k][r],f[l][r]);
			}
		} 
	}
	for(int i = 1;i <= n;i ++) f[i][i]=0;
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=1e9;
		for(int i = 0;i < kk[x].size();i ++){ 
			for(int j = 0;j < kk[y].size();j ++){
				long long pp=kk[x][i],qq=kk[y][j];
				ans=min(ans,f[pp][qq]+tt[x][pp]+tt[y][qq]);
			}
		}
		
		cout<<ans+w[x]+w[y]<<endl;
	}

//	for(int i = 1;i <= m;i ++){
//		for(auto y:kk[i]){
//			cout<<y<<' ';
//		}
//		cout<<endl;
//	}

//	for(int i = 1;i <= n;i ++){
//		for(int j = 1;j <= n;j ++){
//			cout<<f[i][j]<<' ';
//		}
//		cout<<endl;
//	}
}
















