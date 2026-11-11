#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t,n,k,u[2000002],v[2000002];
	cin >> c >> t;
	for(int i = 0;i < t;i++){
		cin >> n >> k;
		for(int j = 0;j < n;j++){
			cin >> u[i] >> v[i];
		}
		sort(u,u+n);
		cout << u[0];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
