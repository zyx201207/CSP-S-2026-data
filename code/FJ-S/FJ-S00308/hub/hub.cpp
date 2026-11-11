#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> T >> T;
	srand(time(NULL));
	while(T--){
		cout << rand()%131 << '\n';
	}
	return 0;
}
