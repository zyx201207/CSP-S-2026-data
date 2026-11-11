#include <bits/stdc++.h> 
using namespace std;
int n,m;
int a[500005];
queue <int> q;
int main(){
	freopen("card,in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cout << a[n];
	return 0;
}
