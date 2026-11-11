#include<bits/stdc++.h>
using namespace std;
int n , m , a[500005] , aa[500005] , ans[300005];
bool a1[500005] , a2[300005];
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	
	for(int i = 1 ; i <= n ; i ++){
		for(int j = i ; j <= n ; j ++){
			if(aa[a[j]] != 0){
				for(int k = aa[a[j]] ; k < j ; k ++){
					a1[k] = 1;
					if(aa[a[k]] == k)aa[a[k]] = 0;
				}
					
				aa[a[j]] = j;
			}
			else aa[a[j]] = j;
		}
		for(int j = i ; j <= n ; j ++){
			if(a[j] <= m && a1[j] == 0 && a2[a[j]] == 0){
				ans[a[j]] ++;
				a2[a[j]] = 1;
			}
		}
		for(int j = 1 ; j <= n ; j ++){
			aa[a[j]] = 0;
			a1[j] = 0;
			a2[a[j]] = 0;
		}
	}
	for(int i = 1 ; i <=m ; i ++)
	cout<< ans[i] << ' ';
	return 0;
}
