#include <bits/stdc++.h>
using namespace std;
char lyx[10000],ddy[10000];
string lly;
const int N = 2*1e5+10;
int n,m,a[N],b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		b[i] = a[i];
	}
	for (int i = 1;i <= n;i++){
		int y = 0,x = 0,d;
		while (b[i] > 0){
			lyx[++y] = b[i]%2;
			b[i] %= 2;
		}while (b[i+1] > 0){
			ddy[++y] = b[i+1]%2;
			b[i+1] %= 2;
		}
		for (int j = 1;j <= max(y,x);j++){
			if (lyx[j] == ddy[j]){
				lly[j] = 1;
			}else{
				lly[j] = 0;
			}
		}
	}
	return 0;
}
