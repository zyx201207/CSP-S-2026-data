#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005];
int main(){
	srand(time(0));
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cout << rand() % 100;
	}
	return 0;
}
