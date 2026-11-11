#include<bits/stdc++.h>
using namespace std;
long long w[1009],k[509],a[509][1009],t[509][1009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,x,y,zt,f;
	cin>>c>>n>>m>>d>>q;
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
		zt=0,f=0;
		cin>>x>>y;
		zt=w[x]+w[y];
		int x1=-1,y1=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					x1=i;
					zt+=t[i][j];
				}else if(a[i][j]==y){
					y1=i;
					zt+=t[i][j];
				}
				if(x1==y1){
					f=1;
					cout<<zt<<endl;
					break;
				}
			}
		}
		if(f==0){
			for(int i=1;i<=k[x1];i++){
				for(int j=1;j<=k[y1];j++){
					if(a[x1][i]==a[y1][j]){
						zt+=(a[x1][i]+a[y1][j]);
						cout<<zt<<endl;
						break;
					}
				}
			}	
		}
	}
	return 0;
}
