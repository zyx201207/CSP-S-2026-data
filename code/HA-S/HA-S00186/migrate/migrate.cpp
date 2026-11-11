#include<bits/stdc++.h>
using namespace std;
long long wei[310];
int dpa[310][310];
int dpb[310][310];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n;
		long long d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>wei[j];
		}
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				dpa[j][l]=1e9;
				dpb[j][l]=0;
			}
		}
		for(int j=2;j<=n;j++){
			for(int l=1;l+j-1<=n;l++){
				if(wei[l+j-1]-wei[l]<=d){
					dpa[l][l+j-1]=1;
					dpb[l][l+j-1]=1;
				}
				else{
					for(int k=l+1;k<l+j-1;k++){
						if(dpa[l][k]+dpa[k][l+j-1]<dpa[l][l+j-1]){
							dpa[l][l+j-1]=dpa[l][k]+dpa[k][l+j-1];
							dpb[l][l+j-1]=dpb[l][k]*dpb[k][l+j-1];
						}
						else if(dpa[l][k]+dpa[k][l+j-1]==dpa[l][l+j-1]){
							dpb[l][l+j-1]+=dpb[l][k]*dpb[k][l+j-1];
						}
					}
				}
				if(dpb[l][l+j-1]>=3){
					dpb[l][l+j-1]=3;
				}
			}
		}
		int z=0;
		for(int k=1;k<=n;k++){
			for(int j=i+1;j<=n;j++){
				if(dpb[k][j]==2){
					z++;
				}
			}
		}
		cout<<z<<'\n';
	}
	return 0;
}
