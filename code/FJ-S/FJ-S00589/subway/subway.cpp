#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
long long w[500005];
int go_k[505];
int go_a[505][500005];
int go_t[505][500005];
int g[500005][500005];
int x,y;
int time_,ttt;
int cx=1000;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>go_k[i];
		for(int j=1;j<=go_k[i];j++){
			cin>>go_a[i][j];
			cin>>go_t[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		cin>>go_k[i];
		for(int j=1;j<=go_k[i];j++){
			cin>>go_a[i][j];
			cin>>go_t[i][j];
		}
		for(int j=1;j<=go_k[i];j++){
			for(int o=1;o<=go_k[i];o++){
				if(j!=o){
					g[j][o]=go_t[i][j]+go_t[i][o];
					g[o][j]=go_t[i][j]+go_t[i][o];
				}
			}
		}
	}
	while(cx--){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int o=1;o<=m;o++){
					if(i!=j!=o && g[i][o] && g[j][o] && !g[i][j]){
						g[i][j]=g[i][o]+g[j][o];
						g[j][i]=g[i][o]+g[j][o];
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		time_+=w[x];
		time_+=w[y];
		cout<<time_+g[x][y]<<endl;
	}
	return 0;
}
