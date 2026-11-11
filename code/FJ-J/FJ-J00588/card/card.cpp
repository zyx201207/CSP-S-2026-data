#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool leave[500005];
int endp[500005];
int ans[500005];
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i ++ ) {
		cin >> a[i];
		endp[a[i]] = -1;
	}
	for(int i = n - 1 ; i >= 0 ; i --) {
		if(endp[a[i]] == -1){
			endp[a[i]] = i;
		}else{
			if(leave[ endp[ a[i]]]){
				endp[a[i]] = i;
			}else{
				for(int j = i ; j < endp[a[i]] ; j ++) {
					leave[j] = true;//дц╣Т 
				}
			}
		}
		for(int j = i ; j < n ; j ++) {
			if(!leave[j]){
				ans[a[j]]++;
//				cout << a[j] << " ";
			}
		}
//		cout << "\n";
	}
	for(int i = 1 ; i <= m ; i ++) {
		cout << ans[i] << " ";
	}
	return 0;
}
//10 3 3 1 2 1 3 2 3 1 2 1
