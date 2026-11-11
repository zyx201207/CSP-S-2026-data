#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll arr[200005];
char ch[200005];

int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	for(int i = 1;i <= n;i++) cin >> arr[i] >> ch[i];
	
	ll ans = 0;
	int i = 1;
	int j = n;
	while(i < j) {
		if(ch[i] != ch[j]) ans += min(arr[i] , arr[j]);
		arr[i] -= min(arr[i] , arr[j]);
		arr[j] -= min(arr[i] , arr[j]);
		
		if(arr[i] <= 0) i++;
		if(arr[j] <= 0) j--;
	}
	cout << ans << endl;
	
	return 0;
}
