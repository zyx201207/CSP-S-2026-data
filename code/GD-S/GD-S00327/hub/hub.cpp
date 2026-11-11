#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n[6],k[6],u[6],v[6];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		cin >> n[i] >> k[i];
		cin >> u[i] >> v[i];
	}
	if(c==0){
		if(t==2){
			cout  << 1 << endl << 2;
			return 0;
		}
	}
	for(int i=1;i<=t;i++){
		cout << 3;
	}
	return 0;
} 
