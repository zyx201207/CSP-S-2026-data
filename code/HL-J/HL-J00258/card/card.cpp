#include<bits/stdc++.h>
using namespace std;
int n , m ;
int a[500005];
int ans[300005];
map<int,int> ma ;
int f[300005];
int main(){
//	freopen("card.in" , "r" , stdin);
//	freopen("card.out" , "w" , stdout);
	cin.tie(0);
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	for(int k = 1 ; k <= n ; k++){
		ma.clear();
		memset(f , 0 , sizeof f);
		int pos = 0 ;
		for(int i = k ; i <= n ; k++){
			if(!f[a[i]]){
				ma[a[i]] = i ;
				f[a[i]] = 1;
				pos++;
			}else{
				for(int j = ma[a[j]] ; j <= pos ; j++){
					ma[a[j]] = 0 ;
					f[a[j]] = 0 ;
				}
				pos = i ;
				ma[a[i]] = i ;
				f[a[i]] = 1;
			}
		}
		for(int i = 1 ; i <= m ; i++){
			if(f[i]){
				ans[i]++;
			}
		}
	}
	for(int i = 1 ; i <= m ; i++){
		cout << ans[i] << ' ' ;
	}
	return 0 ;
}


