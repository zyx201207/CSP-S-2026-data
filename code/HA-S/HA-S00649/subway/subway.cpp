#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int a[1000];
	for(int i = 1;i <= m;i++){
		cin >> a[i];
	}
	int b[10000];
	int f[10000];
	int e = 0;
	for(int i = 1;i <= n;i++){
		cin >> b[i];
		int r = 2 * b[i];
		e += r;
		for(int j = 1 + e;j <= e + r;j++){
			cin >> b[j];
		}
	}
	int h[1000];
	for(int i = 1;i <= 2 * q;i+=2){
		cin >> h[i];
		cin >> h[i + 1];
	}
	for(int i = 1;i <= q;i++){
		for(int i = 1;i <= h[q];i++){
			cout << b[q];
		}
	} 
	return 0;
}
