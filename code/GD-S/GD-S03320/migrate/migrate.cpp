#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t,n,d;
	cin >> c >> t;
	for(int o = 1;o <= t;o++){
		cin >> n >> d;
		int a[n];
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		cout << (n%(d+2)+1)*(d/2) << endl;
	}
	
	return 0;
} 

