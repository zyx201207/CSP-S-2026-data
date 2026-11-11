#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	int ans[t+1];
	for(int z=1;z<=t;z++){
		int n,k;
		cin >> n >> k;
		int u[n],v[n];
		for(int i=1;i<n;i++){
			cin >> u[i] >> v[i];
		}
		ans[z]=(n-k)/k;
	}
	for(int i=1;i<=t;i++){
		cout << ans[i]  << endl;
	}
	return 0;
} 
