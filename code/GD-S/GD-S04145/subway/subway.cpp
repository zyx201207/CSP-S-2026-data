//start 14:59:57
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1]={},k[n+1]={},a[n+1][d+1]={},t[n+1][d+1]={},x[q+1]={},y[q+1]={};
	bool subway[n+1][m+1]={};
	for(int i(1);i<=m;i++)cin>>w[i];
	for(int i(1);i<=n;i++){
		cin>>k[i];
		for(int j(1);j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			subway[i][a[i][j]]=1;
		}
	}
	int mapp[m+1][m+1]={0x7ffffff};
//	memset(mapp,0,sizeof(mapp));
	for(int i(1);i<=m;i++)
		for(int j(1);j<=m;j++)
			mapp[i][j]=0x7fffffff;
	for(int i(1);i<=m;i++){
		for(int j(1);j<=n;j++){
			if(!subway[j][i])continue;
			for(int k(1);k<=m;k++){
				if(!subway[j][k])continue;
				mapp[i][k]=min(mapp[i][k],t[j][i]+t[j][k]);
//				if(mapp[i][k]==11)cout<<j<<"  "<<t[j][i]<<" "<<t[j][k]<<"   "<<i<<" "<<k<<'\n';
			}
		}
	}
	for(int i(1);i<=m;i++){
		for(int j(1);j<=m;j++){
			if(mapp[i][j]==0x7fffffff)continue;
			for(int k(1);k<=m;k++){
				if(mapp[j][k]==0x7fffffff)continue;
				mapp[i][k]=min(mapp[i][k],mapp[i][j]+mapp[j][k]);
				mapp[k][i]=mapp[i][k];
			}
		}
	}
//	for(int i(1);i<=m;i++){
//		for(int j(1);j<=m;j++){
//			cout<<mapp[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int i(0);i<q;i++){
		cin>>x[i]>>y[i];
		cout<<w[x[i]]+w[y[i]]+mapp[x[i]][y[i]]<<'\n';
	}
	return 0;
} 
/*
十万年写出来的暴力解（目前小数据可过吧）Ow< 
end 16:39:02
*/
