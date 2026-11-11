//GZ-S00170 张哲睿 贵阳市新世界学校
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500011],sum[7010][7010];
int cnt=0;
int add(int u,int v,int ww){
	sum[u][v]=ww;
	sum[v][u]=ww;
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cnt=m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		cnt++;
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin>>aa>>tt;
			add(aa,cnt,tt);
		}
	}
	for(int k=1;k<=cnt;k++){
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=cnt;j++){
				if(sum[i][k] && sum[k][j]){
					long long ss=sum[i][k]+sum[k][j];
					if(sum[i][j]){
						sum[i][j]=min(sum[i][j],ss);
						sum[j][i]=min(sum[j][i],ss);
					}else{
						sum[i][j]=ss;
						sum[j][i]=ss;
					}
				}
			}
		} 
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<sum[x][y]+w[x]+w[y]<<'\n'; 
	}
	return 0;
} 
