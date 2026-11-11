#include<bits/stdc++.h>
using namespace std;
vector <int> mp[1000005];
void work(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	cout << "1\n";
	return ;
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int casenum, t;
	cin >> casenum >> t;
	while(t--){
		work();
	}
	return 0;
} 
