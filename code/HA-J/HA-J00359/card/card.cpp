#include<bits/stdc++.h>
using namespace std;
int n , m , a[500005] , ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n >>m;
	for(int i = 1;i <= n;i++){
		cin >>a[i];
	}
	for(int q = 1;q <= n;q++){
		int x = 0;
		for(int i = q;i <= n;i++){
			for(int j = i;j <= n;j++){
				if(a[j] == a[i]){
					x = j;
				}
			}
			i = x;
			ans[a[x]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
