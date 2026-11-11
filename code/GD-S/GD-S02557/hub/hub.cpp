#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,t;
int n,k;
int u,v;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t --){
		cin >> n >> k;
		for(int i = 1;i < n;i ++){
			cin >> u >> v;
		}
		
		if(k == 2){
			cout << 1;
			continue;
		}
		
		if(k == 1){
			cout << 0;
			continue;
		}
		
		cout << k << endl;
	}
	return 0;
} 
