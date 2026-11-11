#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	srand(time(0));
	
	int n = rand() % 10 + 1, m = rand() % n + 1;
	cout << n << " " << m << "\n";
	for(int i = 1; i <= n; i++){
		int x = rand() % 1024;
		cout << x << " ";
	}
	cout << "\n";
	
	
	return 0;
}
