#include<bits/stdc++.h>
using namespace std;
int cc,n,m,d,q,w[50005]={0},k[505]={0},p,z,a[505][50005]={0},t[505][50005]={0},x,y,aa[5005][5005]={0};
bool c[500005]={0};
int sss(){
	int dp[50005]={0},gg=0;
	dp[x]=w[x];
	z=x;
	for(int k=1;k<=n;k++){
		gg=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(aa[i][j]!=0&&dp[i]!=0){
					dp[j]=min(dp[j],dp[i]+t[aa[i][j]][i]+t[aa[i][j]][j]);
					gg=1;
				}
			}
		}
		if(gg==0){
			break;
		}
	}
	dp[y]+=w[y];
	return dp[y];
}
int ssss(){
	int dp[50005]={0},gg=1;
	dp[x]=w[x];
	while(gg){
		gg=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(dp[a[i][j]]!=0){
					for(int h=1;h<=k[i];h++){
						if(dp[a[i][j]]+t[i][a[i][h]]+t[i][a[i][j]]<dp[a[i][h]]){
							dp[a[i][h]]=dp[a[i][j]]+t[i][a[i][h]]+t[i][a[i][j]];
							gg=1;
						}
					}
				}
			}
		}
	}
	dp[y]+=w[y];
	return dp[y];
}
int sssss(){
	int T=t[1][1],dp[500005]={0},minn=0;
	dp[x]=1;
	while(dp[y]==0){
		for(int i=1;i<=n;i++){
			minn=5000005;
			for(int j=1;j<=k[i];j++){
				if(minn>dp[a[i][j]]&&dp[a[i][j]]!=0){
					minn=dp[a[i][j]];
				}
			}
			for(int j=1;j<=k[i];j++){
				if(minn<dp[a[i][j]]){
					dp[a[i][j]]=minn+1;
				}
			}
		}
	}
	dp[y]=(dp[y]-1)*T+w[x]+w[y];
	return dp[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(7<=cc&&cc<=11){
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
			}
			aa[a[i][1]][a[i][2]]=i;
			aa[a[i][2]][a[i][1]]=i;
		}
	}else{
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(7<=cc&&cc<=11){
			cout<<sss()<<endl;
		}else{
			if(12<=cc&&cc<=19){
				cout<<sssss()<<endl;
			}else{
				cout<<ssss()<<endl;
			}
		}
	}
	return 0;
}
