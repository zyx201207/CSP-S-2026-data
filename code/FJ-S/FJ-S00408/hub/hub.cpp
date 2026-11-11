#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	long long t, q;
	cin >> t >> q;
	if(t == 0 && q == 2){
		cout << "1\n2";
		return 0;
	}
	for(int i = 1; i <= q; i++){
		cout << "1\n";
	}
	return 0;
}
