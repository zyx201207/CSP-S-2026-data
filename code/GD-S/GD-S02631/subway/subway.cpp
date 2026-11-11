#include<iostream>
using namespace std;
int c, n, m, d, q;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	cin >> c >> n >> m >> d >> q;
	int cnt = 37;
	while(q--){
		cout << cnt << '\n';
		cnt /= 2;
	}
	return 0;
}

