#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int x,y;
	int w[m+1],ans[m+1];
	ans[0] = 0;
	for (int i = 1;i <= m;i++){
		cin >> w[i];
		ans[i] = ans[i-1]+w[i];
	}
	while (q--){
		cin>> x >> y;
		cout << ans[y]-ans[x-1] << "\n";
	}
}
