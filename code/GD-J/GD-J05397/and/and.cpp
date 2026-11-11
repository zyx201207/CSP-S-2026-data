#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[200005][32],f,x[200005],y[200005],cnx,cny;
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[++cnx]=i;
		for(int j=0;j<=30;j++){
			vis[i][j]=(a[i]>>j)&1;
		}
	}
	for(int i=30;i>=0;i--){
		if(!f){
			for(int j=1;j<=cnx;j++){
				if(vis[x[j]][i]){
					y[++cny]=x[j];
				}
			}
			if(cny<m){
				cny=0;
			}
			else{
				f=!f;
				cnx=0;
				ans+=(1<<i);
			}
		}
		else{
			for(int j=1;j<=cny;j++){
				if(vis[y[j]][i]){
					x[++cnx]=y[j];
				}
			}
			if(cnx<m){
				cnx=0;
			}
			else{
				cny=0;
				f=!f;
				ans+=(1<<i);
			}
		}
	}
	cout<<ans;
	return 0;
}
