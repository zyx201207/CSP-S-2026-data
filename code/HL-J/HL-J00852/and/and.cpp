#include<bits/stdc++.h>

using namespace std;
int n, m;
int a[100000010];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(m == 1){
		sort(a+1, a+n+1);
		cout << a[n];
		return 0;
	} else if(m == 2){
		int ma = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				if(a[i]&a[j] > ma) ma = a[i]&a[j];
			}
		}	
		cout << ma;
	}
	
	return 0;
}