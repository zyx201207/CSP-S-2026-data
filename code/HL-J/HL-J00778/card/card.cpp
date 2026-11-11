#include<bits/stdc++.h>
using namespace std;
const int A = 2e5+5;
int a[A] , top = 0 , n  , m , cnt[A];
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cnt[i] = i;
	if(m == 1) {
		cout << n;
		return 0;
	}
	if(m == 2){
		for(int i = n;i >= 1;i --){
		}
	}
	return 0;
}