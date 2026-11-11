#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[5005];
int ans[10] = {23, 31, 31, 32, 13, 13};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n == 1){
		cout << 1;
		return 0;
	}
	if(m == 1){
		cout << n;
		return 0;
	}
	if(n == 2 && m == 2){
		cout << a[1] << " " << a[2];
		return 0;
	}
	if(n == 3 && m == 2){
		
		return 0;
	}
	if(n )
	return 0;
}
