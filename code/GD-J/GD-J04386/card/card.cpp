#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int a[N];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout); 
	int n, m;
	cin >> n >> m;
	for (int i =1; i <= n; i++) cin >> a[i];
	cout << rand() % n << " " << rand() % n << " " << rand() % n << endl; 
	return 0;
}
