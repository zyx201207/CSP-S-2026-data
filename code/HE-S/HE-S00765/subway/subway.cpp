#include<bits/stdc++.h>//44
using namespace std;
int c,n,m,d,q,a[500005];
vector<int> mieval[500005];
long long mappa[2503][2503];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=11){
		long long shu=(1<<30);
		for(int i=1;i<=m*2+n;i++){
			for(int j=1;j<=m*2+n;j++){
				mappa[i][j]=shu;
			}
		}
		for(int i=1;i<=m;i++){
			int ww;
			cin>>ww;
			mappa[i][m+i]=ww;
			mappa[m+i][i]=ww;
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int aa,tt;
				cin>>aa>>tt;
				mappa[m+aa][m*2+i]=tt;
				mappa[m*2+i][m+aa]=tt;
			}
		}
		for(int k=1;k<=m*2+n;k++){
			for(int i=1;i<=m*2+n;i++){
				for(int j=1;j<=m*2+n;j++){
					mappa[i][j]=min(mappa[i][j],mappa[i][k]+mappa[k][j]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<mappa[x][y]<<'\n';
		}
		return 0;
	}
	else if(c>=12 && c<=19){
		for(int i=1;i<=m;i++){
			int ww;
			cin>>ww;
			a[i]=ww;
		}
		int tt;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int aa;
				cin>>aa>>tt;
				mieval[aa].push_back(i);
			}
		}
		long long mappa[505][505],shu=(1<<30);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mappa[i][j]=shu;
				if(i==j){
					mappa[i][j]=0;
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<mieval[i].size();j++){
				mappa[mieval[i][j]][mieval[i][j-1]]=tt*2;
				mappa[mieval[i][j-1]][mieval[i][j]]=tt*2;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					mappa[i][j]=min(mappa[i][j],mappa[i][k]+mappa[k][j]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			long long aans=-1;
			for(int i=0;i<mieval[x].size();i++){
				for(int j=0;j<mieval[y].size();j++){
					if(aans=-1){
						aans=mappa[i][j]+a[x]+a[y];
					}
					aans=min(aans,mappa[i][j]+a[x]+a[y]);
				}
			}
			cout<<aans<<'\n';
		}
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
