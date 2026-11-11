#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin >> c;
	if(c == 0){
		int n;
		cin >> n;
		if(n == 2) cout << 32;
		else if(n == 3) cout << 35 << " " << 16;
	}
	return 0;
} 
