#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	srand(time(0));
	
	int n = rand() % 10 + 1;
	cout << n << "\n";
	for(int i = 1; i <= n; i++){
		int x = rand() % 5 + 1;
		char c = rand() % 3 + 'a';
		cout << x << " " << c << "\n";
	}
	
	
	return 0;
}
