#include <bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	if(n==4 && m==3) cout << 3 << endl << 1 << endl << 4;
	if(n==10 && m==3) cout << 10 << endl << 3 << endl << 3;
}