#include<bits/stdc++.h>
using namespace std;
pair <long long, char> mp[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> mp[i].first >> mp[i].second;
	}
	int x = 1, y = n;
	while(x < y){
		if(mp[x].first == mp[y].first){
			ans += 1ll * (mp[x].second != mp[y].second) * mp[x].first;
			mp[x].first = 0;
			mp[y].first = 0;
			x++;
			y--;
		} else if(mp[x].first > mp[y].first){
			ans += 1ll * (mp[x].second != mp[y].second) * mp[y].first;
			mp[x].first -= mp[y].first;
			mp[y].first = 0;
			y--;
		} else {
			ans += 1ll * (mp[x].second != mp[y].second) * mp[x].first;
			mp[y].first -= mp[x].first;
			mp[x].first = 0;
			y++;
			
		}
	} 
	cout << ans;
	return 0;
}
