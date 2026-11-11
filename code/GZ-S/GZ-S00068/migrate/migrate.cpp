//GZ-S00068 清镇市第一中学 蒋煜
#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int c,t;
int x[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i = 1;i<=t;i++){
        int n,d;
		cin >> n >> d;
		for(int j = 1;j<=n;j++){
			cin >> x[i][j];
		}
		int a,b;
		a = x[i][1];
		b = x[i][n];
		cout << (b-a)/d;
	}
	return 0;
}
