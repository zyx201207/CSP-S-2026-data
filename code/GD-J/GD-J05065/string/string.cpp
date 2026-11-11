#include <bits/stdc++.h>
using namespace std;
int n;
string a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		int c;
		char inp;
		cin >> c >> inp;
		for(int j = 1 ; j <= c ; j++){
			a += inp;
		}
	}
	int mid , ans;
	int l = a.size();
	if(l % 2 == 0){
		mid = l / 2 - 1;
		for(int i = 0 ; i <= mid ; i++){
			int j = l - i - 1;
			if(a[i] != a[j]){
				ans++;
			}
		}
	}else{
		mid = (l - 1) / 2;
		for(int i = 0 ; i < mid ; i++){
			int j = l - i - 1;
			if(a[i] != a[j]){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
