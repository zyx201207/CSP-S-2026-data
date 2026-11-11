#include <bits/stdc++.h>
using namespace std;
long long n,m,a[600000],ans[400000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
    	cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
    	int mk[400000] = {};
    	for(int j = n;j >= i;j--){
    		if(mk[a[j]]){
    			for(int k = j + 1;a[k] != a[j];k++){
    				ans[a[k]]--;
    			}
    			break;
    		}
    		mk[a[j]] = 1;
    		ans[a[j]]++;
    	}
    }
    for(int i = 1;i <= m;i++){
    	cout << ans[i] << " ";
    }
	return 0;
}
