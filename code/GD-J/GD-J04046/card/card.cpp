#include<iostream>
#include<cstdio>
using namespace std;

int n, m;
int a[500005];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.ans", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++){
		 cout << a[i];
	}
	return 0;
} 
