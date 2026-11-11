#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[99999];
int k[509][500009];
int t[509][500009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i][0];
		for(int j = 1;j <= k[i][0];j++){
			cin >> k[i][j];
			cin >> t[i][j];
		}
	}
	for(int i = 1;i <= q;i++){
		int x,y;
		cin >> x >> y;
		int s = 0;
		s += w[x] + w[y];
		int a[d + 1][d + 1];
		int ii = 1;
		for(int j = 1;j <= n;j++){
			for(int kk = 1;kk <= k[j][0];kk++){
				if(k[j][kk] == x){
					a[0][ii] = kk;
					a[ii][0] = j;
					ii += 1;
				}
			}
		}
		int b[d + 1][d + 1];
		int iii = 1;
		for(int j = 1;j <= n;j++){
			for(int kk = 1;kk <= k[j][0];kk++){
				if(k[j][kk] == y){
					b[0][iii] = kk;
					b[iii][0] = j;
					iii += 1;
				}
			}
		}
		int f = 1;
		for(int o = 1;o <= ii;o++){
			if(f == 0){
				break;
			}
			for(int oo = 1;oo <= iii;oo++){
				if(a[o][0] == b[oo][0]){
					s += t[a[o][0]][a[0][o]];
					s += t[b[oo][0]][b[0][oo]];
					f = 0;
					cout << s << endl;
					break;
				}
			}
		}

	}
	return 0;
}
