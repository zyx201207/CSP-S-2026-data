#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} 
	for(int i=1;i<=n;i++){
		cout << n-i << " ";
	}
	return 0;
}
