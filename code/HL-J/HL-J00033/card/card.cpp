#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,k;
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> k;
	for(int i = 1,x; i <= n; i++){
		cin >> x;
		if(!ans[x]) ans[x] = n - i;
	}
	for(int i = 1; i <= k; i++) {
		if(i == k) ans[i]++;
		cout << ans[i] << ' ';
	}
	return 0;
}