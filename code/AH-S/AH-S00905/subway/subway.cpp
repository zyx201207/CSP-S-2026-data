#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=505,M=10005;
int n,m,c,d,q;
int w[M];
int f[M][M];
int ans;
int t[M][N];
void Floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		int k,a,time;
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a >> time;
			t[a][i]=time;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			for(int k=j+1;k<=m;k++){
				if(t[j][i]>0&&t[k][i]>0){
					f[j][k]=t[j][i]+t[k][i];
				}
			}
		}
	}
	Floyd();
	while(q--){
	 	int s,e;
	 	cin >> s >> e;
	 	cout << w[s]+f[s][e]+w[e] << '\n';
	} 
	return 0;
}

