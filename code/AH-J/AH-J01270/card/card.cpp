#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1);
	for (int i = 1; i<=n; i++){
		cin >> a[i];
	}
	
	int sum = (n+1)*n/2;
	cout << (n+1)*n/2 << " ";
	int tool = 0;
	for (int i = 2; i<=n; i++){
		cout << sum-1-tool << " ";
		if (i == 2) tool = n;
		else tool += tool-1;
	}
}
