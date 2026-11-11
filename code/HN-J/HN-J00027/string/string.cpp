#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
char a[N];
int cnt[N];
long long ans;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> cnt[i] >> a[i];
	}
	for(int i = 1, j = n; i < j;){
		if(a[i] != a[j]) ans += min(cnt[i], cnt[j]);
		if(cnt[i] < cnt[j]){
			cnt[j] -= cnt[i];
			i++;
		}else if(cnt[i] == cnt[j]){
			i++, j--;
		}else{
			cnt[i] -= cnt[j];
			j--;
		}
	}
	cout << ans;
	return 0;
}
/*

*/
