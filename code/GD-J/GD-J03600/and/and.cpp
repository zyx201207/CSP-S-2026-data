#include <bits/stdc++.h>
using namespace  std;
const int N = 2e5 + 10;
int n,m,arr[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	sort(arr+1,arr+1+n,greater<int>());
	int ans = arr[1],place = 2;
	m--;
	while (m--){
		ans &= arr[place++];
	}
	cout << ans;
	return 0;
}
