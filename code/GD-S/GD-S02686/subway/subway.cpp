#include<bits/stdc++.h>
using namespace std;
long long w[500005];
long long dt[500005][25];
long long dr[500005][25];
long long ki[500005];
long long r2r[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//init
	memset(r2r,-1,sizeof(r2r));
	for(int i=1;i<=500;i++){
		r2r[i][i]=0;
	}
	//--
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int lx;
		cin>>lx;
		for(int j=1;j<=lx;j++){
			long long acx,bcx;
			cin>>acx>>bcx;
			ki[acx]++;
			dt[acx][ki[acx]]=bcx;
			dr[acx][ki[acx]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=ki[i]-1;j++){
			for(int k=j;k<=ki[i];k++){
				int rdj=dr[i][j],rdk=dr[i][k];
				if((dt[i][j]+dt[i][k]<r2r[rdj][rdk])||r2r[rdj][rdk]<0){
					r2r[rdj][rdk]=dt[i][j]+dt[i][k];
					r2r[rdk][rdj]=dt[i][j]+dt[i][k];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(r2r[j][i]>=0&&r2r[i][k]>=0&&(r2r[j][i]+r2r[i][k]<r2r[j][k]||r2r[j][k]<0)){
					r2r[j][k]=r2r[j][i]+r2r[i][k];
					r2r[k][j]=r2r[j][i]+r2r[i][k];
				}
			}
		}
	}
	long long bbg=pow(10,14);
	for(int i=1;i<=q;i++){
		int xxr,yyr;cin>>xxr>>yyr;
		long long ans=bbg;
		for(int j=1;j<=ki[xxr];j++){
			for(int k=1;k<=ki[yyr];k++){
				int rdj=dr[xxr][j],rdk=dr[yyr][k];
				ans=min(r2r[rdj][rdk]+dt[xxr][j]+dt[yyr][k],ans);
			}
		}
		cout<<ans+w[xxr]+w[yyr]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
