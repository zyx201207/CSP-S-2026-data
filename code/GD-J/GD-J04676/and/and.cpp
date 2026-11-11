#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10; 
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int maxn = -1,annd,maxn2 = -1,ans;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxn = max(a[i] , maxn);
	}
	
	for(int i = 1;i <= n;i++){
		if(a[i] != maxn){
			maxn2 = max(a[i] , maxn2);
		}
	}
	
	annd = a[1] & a[2];
	for(int i = 3;i <= n;i++){
		annd = annd & a[i];
	}
	if(m == 1){
		cout << maxn;
	}else if(m == n){
		cout << annd;
	}else{
		ans = maxn & maxn2;
		cout << ans;
	}
	return 0;
} 
