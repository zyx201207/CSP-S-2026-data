#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
const int M = 1e2+10;
long long c,n,m,d,q,know,mkw[N],w[N],k[N],a[M][M],t[M][M],x[N],y[N],nnmm[N];
int main(){
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++){
		cin >> w[i];
	}
	for(int i = 1;i<=n;i++){
		cin >> k[i];
		for(int j = 1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1;i<=q;i++){
		cin >> x[i] >> y[i];
	}
	for(int i1 = 1;i1<=n;i1++){
		for(int j1 = 1;j1<=k[i1];j1++){
			know = a[i1][j1];
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=k[i];j++){
					if(know == a[i+1][j]){
						mkw[i] = a[i][j];
					}
				}
			}
		}
	}
	for(int i = 1;i<=q;i++){
		long long num = 0;
		num+=w[x[i]];
		for(int j = 1;j<=k[i];j++){
			if(a[i][j] == x[i]){
				num+=t[i][j];
			}
			if(a[i][j] == y[i]){
				num+=t[i][j];
			}
			if(a[i][j] != x[i]){
				if(a[i][j] == mkw[i]){
					num+=t[i][j];
				}
			}
		}
		num+=w[y[i]];
		nnmm[i] = num;
	} 
	for(int i = 1;i<=q;i++){
		cout << nnmm[i];
	}
	return 0;
}
