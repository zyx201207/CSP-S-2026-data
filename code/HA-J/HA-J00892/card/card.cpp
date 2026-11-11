#include <bits/stdc++.h>
using namespace std;
int n, m;
int card[500001];
int nums[300001];
bool app[300001];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i<=n;i++){
		cin >> card[i];
	}
	
	nums[card[n]] = n;
	app[card[n]] = 1;
	
	for (int i = n-1;i>=1;i--){
		int cnt = 0;
		for (int j = i;j>=1;j--){
			if(app[card[j]] == 1) break;
			else cnt++;
		}
		app[card[i]] = 1;
		nums[card[i]] = max(nums[card[i]], cnt);
	}
	for (int i = 1;i<=m;i++){
		cout << nums[i] << ' ';
	}
	return 0;
}
