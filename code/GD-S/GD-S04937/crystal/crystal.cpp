#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[500010];
long long max_num = 0;
void search(int a, int b, int used) {
	if(used > m || a > n) return ;
	used += b;
	arr[a] += b;
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if(arr[i] == arr[j]){
				cnt += 1;
				if(cnt == 0) cnt ++;	
			}  
		}
	} 
	max_num = max(max_num,cnt + 1);
	cnt = 0;
	for (int i = 0; i <= m - used; i++) {
		search(a + 1, i, used + i);
	}
	
	if(b + 1 <= m) search(a,b + 1, used + 1);
	arr[a] -= b;
	return ;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	search(1, 0, 0);
	cout << max_num;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
