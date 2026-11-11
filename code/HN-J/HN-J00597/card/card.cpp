#include<bits/stdc++.h>
using namespace std;
int n , m , a[500001] , cnt[300001];
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		cnt[a[i]]++;
		if(a[i] != a[n]) cnt[a[n]]++;
	}
	for(int i = 1;i <= m;i++) cout << cnt[i] << " ";
	return 0;
} 
