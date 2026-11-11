#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,x,y,k;
	cin>>c>>n>>m>>d>>q;
	int w[500005];
	int z[505][25];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			z[x][i]=y;
		} 
	}
	int s=1e9;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int jx=1;jx<=d;jx++){
			for(int jy=1;jy<=d;jy++){
				if((z[x][jx]!=0)&&(z[y][jy]!=0)){
					if(jx==jy){
						s=min(s,(z[x][jx]+z[y][jy]));
					}else{
						for(int j=1;j<=m;j++){
							if((z[j][jx]!=0)&&(z[j][jy]!=0)){
								s=min(s,(z[x][jx]+z[y][jy]+z[j][jx]+z[j][jy]));
							} 
						}
					}
				}
			}
		}
		cout<<s+w[x]+w[y]<<endl;
	}
	return 0;
}
