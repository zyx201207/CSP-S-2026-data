#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[50010],ans;
int k[510],a[510][50010],t[510][50010];
int poin[50010][510];
int v[500010];
//zmjjkkkskblzdjdwkzkblmpwzbyqslnzswpwjsbllcxybtylyzjzdbldsdbllahzmtnzhbylzmmzbza
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			poin[a[i][j]][i]=1;
		}
	}
	while(q--){
		//ans=100000000000;
		//memset(v,0,sizeof(v));
		int x,y,ix,jx,iy,jy;
		cin>>x>>y;//dfs(x,y,0,0);
		if(n==2){
			if(poin[x][1]==poin[y][1]||poin[x][2]==poin[y][2]){
				for(int i=1;i<=n;i++){
					if(poin[x][i]!=poin[y][i]) continue;
					for(int j=1;j<=k[i];j++){
						if(a[i][j]==x){
							ix=i,jx=j;
						}
						if(a[i][j]==y){
							iy=i,jy=j;
						}
					}
				}cout<<w[x]+w[y]+t[ix][jx]+t[iy][jy]<<"\n";
			}
			else{
				for(int i=1;i<=n;i++){
					for(int j=1;j<=k[i];j++){
						if(a[i][j]==x){
							ix=i,jx=j;
						}
						if(a[i][j]==y){
							iy=i,jy=j;
						}
					}
				}//cout<<ix<<" "<<jx<<" "<<iy<<" "<<jy<<"\n";
				long long sum=10000000000000;
				for(int i=1;i<=m;i++){
					if(poin[i][1]==1&&poin[i][2]==1){
						int im,jm,imm,jmm;
						for(int j=1;j<=k[1];j++){
							if(a[1][j]==i){
								im=1,jm=j;
							}
						}
						for(int j=1;j<=k[2];j++){
							if(a[2][j]==i){
								imm=2,jmm=j;
							}
						}//cout<<jmm<<" ";
						long long ans=0;
						ans+=w[x]+w[y];
						ans+=t[ix][jx]+t[im][jm]+t[imm][jmm]+t[iy][jy];
						//cout<<t[ix][jx]<<" "<<t[im][jm]<<" "<<t[imm][jmm]<<" "<<t[iy][jy]<<"  ";
						sum=min(sum,ans);
					}
				}
				cout<<sum<<"\n";
			}
			
			
		}
		//////////////
		else{
			cout<<w[x]+w[y]+2*(y-x)*t[1][1];
		}
		//cout<<(w[x]+ans+w[y])<<"\n";//+wx+wy;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/