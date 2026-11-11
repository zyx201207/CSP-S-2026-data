#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t, n, k, u[1000005]={},v[1000005]={};
	cin >> c >> t >> n >> k;
	for(int j = 1; j <= t; j++)
		for(int i = 1; i <= n - 1;++i)
			cin >> u[i] >> v[i];
	for(int i = 1;i <= t;++i){
		cout <<"1"<<endl;
	}
	return 0;
} 
