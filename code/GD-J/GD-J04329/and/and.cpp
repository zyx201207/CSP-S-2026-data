#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	//输入数据 
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	
	//当n=m时,
	if(n == m){
		long long ans;
		for(int i=1; i<=n; i++){
			if(i != 1){
				ans = ans & a[i];
			}else{
				ans = a[i]; 
			}
		}
		cout << ans;
	} 
	return 0;
} 
