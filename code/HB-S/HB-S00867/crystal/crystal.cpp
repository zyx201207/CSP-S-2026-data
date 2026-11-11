#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll a[500010];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll l = a[1]; 
	ll num = 0; 
	for(int i = 1; i <= n; i++){
		if(m - (num * (a[i] - l)) >= 0){
	 		m -= abs(num * (a[i] - l)); 
       	   	num += 1;
			l = a[i];
		}else{
			break;
		}
	}
	cout << num;
	return 0;
}














//www,fangweikhkhjkhjkhk
