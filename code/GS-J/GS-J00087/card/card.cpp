#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	if (n == 1){
		cout << 1;
		return 0;
	}
	for (int i = 1;i <= m;i++) cout << i << " ";
}
