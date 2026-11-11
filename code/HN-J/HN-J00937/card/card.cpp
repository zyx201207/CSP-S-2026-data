#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 5e5 + 5;
int a[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n>> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= m;i++){
		cout << a[i]<< ' ';
	}
	return 0;
}
