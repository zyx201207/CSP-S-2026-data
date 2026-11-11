//GZ-J00304 遵义市播州区南白初级中学 王耀葵  
#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long cnt = 0, sum = 0, su = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++ ){
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	for(int i = 1, j = n; su <= sum / 2;){
		if(c[i] == c[j]){
			cnt += 0;
		}
		else{
			cnt += min(a[i], a[j]);
		}
		su += min(a[i], a[j]);
		if(su > sum / 2){
			cout << cnt - min(a[i], a[j]);
			return 0;
		}
		a[i] -= min(a[i], a[j]);
		a[j] -= min(a[i], a[j]);
		if(a[i] == 0){
			i ++;
		}
		if(a[j] == 0){
			j --;
		}
	}
	return 0;
}
