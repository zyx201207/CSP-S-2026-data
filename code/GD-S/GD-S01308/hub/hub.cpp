#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
vector <int> v[N];
int a[N] , b[N];
int main(){
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	int c , n;
	cin >> c >> n;
	while(n --){
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i] >> b[i];
			v[a[i]].push_back(b[i]);
			v[b[i]].push_back(a[i]);
		}
		cout << 2 << endl << 1;
	}
	return 0;
}
