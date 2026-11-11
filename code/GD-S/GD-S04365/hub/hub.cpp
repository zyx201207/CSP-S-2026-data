#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	
	int a[t];
	for(int i = 1;i <= t;i++){
		int n,k;
		cin >> n >> k;
		
		int ans = n;
		for(int j = 1;j < n;j++){
			int u,v;
			cin >> u >> v;
			int tmp = v - u;
			ans = min(ans,tmp);
		}
		a[i - 1] = ans;
	}
	
	for(int i = 0;i < t;i++){
		cout << a[i] << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
