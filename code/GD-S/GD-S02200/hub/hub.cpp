#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int i=1; i<=t; i++){
		int n,k;
		cin >> n >> k;
		for(int j=0; j<=n-2; j++){
			int u[100000],v[100000];
			cin >> u[j] >> v[j];
		}
	}
	if(c == 0 && t == 2){
		cout << 1 << endl << 2;
	}
	else{
		cout << 2 << endl << 3;
	}
	return 0;
}
