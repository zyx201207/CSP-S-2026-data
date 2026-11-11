#include <bits/stdc++.h>
using namespace std;
int c,t;
int a[100005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t --){
		int n ,k;
		cin >> n >> k;
		cout << (n-k) % 9 << "\n";
	}
	return 0;
}
