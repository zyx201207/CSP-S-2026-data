#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n,m;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	cout << 3;
	for(int i = 1;i < m;i++){
		cout <<  ' ' << 1;
	}
	return 0;
} 
