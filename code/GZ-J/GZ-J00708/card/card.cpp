//ÀîÔóÈğ GZ-J00728 
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n;
	cin >> n;
	int k;
	cin >> k;
	a.resize(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 0; i < k; i++){
		cout << rand() % 10000 << " ";
	}	
	return 0;
}
