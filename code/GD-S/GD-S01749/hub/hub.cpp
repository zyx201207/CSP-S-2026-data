#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u[2000001],v[2000001]; 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> k;
		for(int j = 0; j < n; j++){
			cin >> u[j] >> v[j];
		}
		sort(u+0,u+n+0);
		cout << u[0]; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
