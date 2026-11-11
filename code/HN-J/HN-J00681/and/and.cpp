#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n , m , c , ans = 0 , ans2 = 0;
	cin >> n >> m;
	int a[n+5] = {};
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		cout << i << endl; //---------------------
		for(int j = i + m;j < n;i++){
			cout << j << endl; //-----------------
			for(int k = j;k < j+m;k++){
				ans2 += i & k;
			}
			if(ans2 > ans){
				ans = ans2;
			}
			ans2 =0;
		}
	}
	cout << ans;
	return 0;
}
