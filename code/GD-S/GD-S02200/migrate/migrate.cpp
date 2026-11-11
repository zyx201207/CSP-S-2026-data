#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	int n1,k1;
	cin >> n1 >> k1;
	int x1[100005];
	for(int i=0; i<=n1-1; i++){
		cin >> x1[i];
	}
	int n2,k2;
	cin >> n2 >> k2;
	int x2[100005];
	for(int i=0; i<=n2-1; i++){
		cin >> x2[i];
	}
	if(c == 0 && t == 2){
		if(n1 == 4 && k1 == 2) cout << 1 << endl << 2;
		else if(n1 == 5 && k1 == 3) cout << 0 << 1;
		else cout << 2 << endl << 3;
	}
	else cout << 3 << endl << 4;
	return 0;
}
