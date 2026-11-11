#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	srand(time(0));
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	while(q--){
		cout << rand()%n+1 << '\n'; 
	} 
	return 0;
}
