#include<bits/stdc++.h>
using namespace std;

long long n,a[200005];
char q[200005];
long long ans = 0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> q[i];
	}
	long long e = n,i = 1;
	while(e >= i){
		if(q[i] != q[e]){
			if(a[i] < a[e]){
				ans += a[i];
				a[e] -= a[i];
				i++;
			}
			else if(a[i] == a[e]){
				ans += a[e];
				i++;
				e--;
			}
			else{
				ans += a[e];
				a[i] -= a[e];
				e--;
			}
		}
		else{
			if(a[i] < a[e]){
				a[e] -= a[i];
				i++;
			}
			else if(a[i] == a[e]){
				i++;
				e--;
			}
			else{
				a[i] -= a[e];
				e--;
			}
		}
	}
	cout << ans;
	return 0;
}
