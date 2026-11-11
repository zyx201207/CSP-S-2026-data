#include <bits/stdc++.h>
using namespace std;

long long n, num[200005], ans;
char alph[200005];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1;i <= n; i++)  cin >> num[i] >> alph[i];
	
	long long l = 1, r = n;
	while(l < r){
		if(alph[l] != alph[r]){
			ans += min(num[l], num[r]);
	    }
		if(num[l] > num[r]){
			num[l] -= num[r];
			r--; 
		}else if(num[l] < num[r]){
			num[r] -= num[l];
			l++; 
		}else if(num[l] == num[r]){
			l++, r--; 
		}
	}
	
	cout << ans;
	
	return 0;
}
