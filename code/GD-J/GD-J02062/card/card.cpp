#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> b(m,1);
	b[a[n - 1] - 1] = n;
	for(int i = 0; i < m; i++){
		cout << b[i] << " ";
	}
	return 0;
}
