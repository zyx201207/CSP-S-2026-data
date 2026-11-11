#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using LL = long long;

int n, a[N];
LL ans;
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i] >> c[i];
	}
	
	for(int i = 1, j = n; i < j;){
		if(a[i] < a[j]){
			if(c[i] != c[j]){
				ans += a[i];
			}
			
			a[j] -= a[i];
			i++;
		}else if(a[i] > a[j]){
			if(c[i] != c[j]){
				ans += a[j];
			}
			
			a[i] -= a[j];
			j--;
		}else{
			if(c[i] != c[j]){
				ans += a[i];
			}
			
			j--;
			i++;
		}
	}
	
	cout << ans << "\n";
	return 0;
}
