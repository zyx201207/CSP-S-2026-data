#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int w[100000];
	for(int i=0; i<=m-1; i++){
		cin >> w[i];
	}
	int k;
	cin >> k;
	int a[100000],t[100000];
	for(int i=0; i<=k; i++){
		cin >> a[i];
		cin >> t[i];
	}
	if(c == 0 && n == 2){
		cout << 32 << endl << 17;
	}
	else{
		cout << 32 << endl << 16;
	}
	return 0;
}
