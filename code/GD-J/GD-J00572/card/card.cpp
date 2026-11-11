#include <bits/stdc++.h>
using namespace std;
int a[500010];
int ans[500010];
int arr[500010];
int p[500010];
int n, m;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	int q = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] < a[i-1]){
			q = 0;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 500000;j++){
			arr[i] = p[i] = 0;
		}
		int e = 0;
		for(int j = i;j <= n;j++){
			if(p[a[j]] == 0){
				p[a[j]] = 1;
				arr[e+1] = a[j];
				e++;
			}else if(p[a[j]] == 1){
				for(int k = 1;k <= e;k++){
					if(arr[k] == a[j]){
						for(int w = k+1;w <= e;w++){
							p[arr[w]] = 0;
							arr[w] = 0;
						}
						e = k;
						break;
					}
				}
			}
		}
		for(int j = 1;j <= e;j++){
			ans[arr[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[a[i]] << " ";
	}
	return 0;
}
