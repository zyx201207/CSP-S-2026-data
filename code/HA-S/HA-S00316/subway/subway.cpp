#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
int k[505],a[505][500005],t[505][500005],dp[505][505][25],tt[500005];
long long duan(int x,int y){
	int ans=0;
	ans+=w[x]+w[y]+tt[x]+tt[y];
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(tt,999999,sizeof(tt));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<505;i++){
		for(int j=0;j<505;j++){
			for(int k=0;k<25;k++){
				dp[i][j][k]=999999;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			tt[a[i][j]]=min(tt[a[i][j]],t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<duan(x,y)<<endl;
	}
	return 0;
}
