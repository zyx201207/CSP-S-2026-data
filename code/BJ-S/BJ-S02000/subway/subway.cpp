#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[5005],k[5005],a[5005][5005],t[5005][5005];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y,qx,qy,zx,zy;
		cin>>x>>y;
		int cx[5005],cy[5005];//chuan song dian zuo biao
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					qx=i,qy=j;
				}
				if(a[i][j]==y){
					zx=i,zy=j;
				}
				if(a[i][j]==a[i+j-1][j+j-1]){
					cx[i]=i;cy[j]=j;
				}
			}
		}
		int sum=0;
		for(int i=qx;i<=n;i++){
			for(int j=qy;j<=k[i];j++){
				if(qx==zx){
					sum+=w[x];
					while(qy!=zy){
						sum+=t[i][j];
					}
				}else{
					sum+=w[x];
					while(qy!=cy[i]){
						sum+=t[i][j];
					}
					qx=cx[i];qy=cy[i];
					while(qy!=zy){
						sum+=t[i][j];
					}
				}
			}
			sum+=w[y];
		}
		cout<<sum<<endl;
	}
	return 0;
}
