#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n , m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	cout << n << m << a[1];
	return 0;
} 
