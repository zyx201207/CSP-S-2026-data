#include <bits/stdc++.h>
using namespace std;
int t[500005];
int ans[500005];
int main(){	
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	vector<int>a(n + 1);
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			t[a[j]]++;
			ans[a[j]]++;
			if(t[a[j]] == 2){
				for(int k = j - 1;k >= i;k--){
					if(a[j] != a[k] && t[a[k]] > 0){
						ans[a[k]]--;
						t[a[k]]--;							
					}
	
								
					if(a[j] == a[k]){
						ans[a[k]]--;
						t[a[k]]--;
						break;
					}

				}
			}
		}
		memset(t , 0 , sizeof(t));
	}
	for(int i = 1;i <= m;i++)cout << ans[i] <<" ";
	return 0;
}
