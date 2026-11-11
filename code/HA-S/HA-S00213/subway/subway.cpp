#include<bits/stdc++.h>
using namespace std;
struct kat{
	int a;
	int t;
};
kat k[502][200100];
int n,m,c,d,q,w[500005],nk[505],t[505][500005],tllt[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>nk[i];
		for(int j=1;j<=nk[i];j++){
			cin>>k[i][j].a>>k[i][j].t;
			t[i][k[i][j].a]=j;
		}
	}
	
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			tllt[i][j]=1000005;
			int mi=min(nk[i],nk[j]);
			int find1;
			if(mi==nk[i])find1=i;
			else find1=j;
			int find2=i+j-find1;
			for(int at=1;at<=nk[find1];at++){
				int find1ka=k[find1][at].a;
				int find1kt=k[find1][at].t;
				if(t[find2][find1ka]!=0){
					tllt[i][j]=min(find1kt+k[find2][t[find2][find1ka]].t,tllt[i][j]);
				}
			}
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int xz=1;xz<=n;xz++){
				int fi=max(xz,i),si=max(xz,j);
				int fj=min(xz,i),sj=min(xz,j);
				if(tllt[i][j]>tllt[fi][fj]+tllt[si][sj]){
					tllt[i][j]=tllt[fi][fj]+tllt[si][sj];
				}
			}
		}
	}
	while(q--){
		int x,y,cans=9999999;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			int wzx=t[i][x];
			if(wzx!=0){
				for(int j=1;j<=n;j++){
					int wzy=t[j][y];
					if(wzy!=0){
						int ans=0;
						if(i!=j){
							ans+=tllt[max(i,j)][min(i,j)];
						}
						ans+=k[i][wzx].t+k[j][wzy].t;
						cans=min(ans+w[x]+w[y],cans);
					}
				}
			}
		}
		cout<<cans<<"\n";
	}
	return 0;
}