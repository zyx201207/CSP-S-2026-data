#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int g,c;
	cin >> g >> c;
	while(c--){
		int n,m;
		cin >> n >> m;
		int a,b;
		cin >> a >> b;
		int dc=abs(a-b);
		if(dc<=m){
			cout << 0 << endl;
			continue;
		}
		cout << n-m-1 <<endl;
	}
	
	return 0;
}
