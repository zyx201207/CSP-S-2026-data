#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ti,ai;
long long w[1000],k[50],t[50000][100],a[50000][100],dx[10000][2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i < m;i++){
		cin >> w[i];
	}
	for(int i = 0;i < n;i++){
		cin >> k[i];
		for(int j = 0;j < 2*k[i];j++){
			if(j%2==0){
				cin >> a[j/2][i];
			}else{
				cin >> t[j/2][i];
			}
		}
	}
	for(int i = 0;i < q;i++){
		cin >> dx[i][0] >> dx[i][1];
		cout << w[dx[i][0]] + t[dx[i][0]][dx[i][0]] + t[dx[i][0]][dx[i][1]] + w[dx[i][1]] << endl;
	}
	return 0;
}
