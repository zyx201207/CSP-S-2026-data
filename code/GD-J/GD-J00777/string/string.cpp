#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
long long cnt , ans;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	int n;
	cin >> n;
	cnt = n;
	for(int i =1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	for(int i = 1;i <= cnt;i++){
		if(a[i] == a[cnt]){
			if(c[i] == c[cnt]){
				cnt--;
				continue;
			}
			else{
				ans += a[i];
				cnt--;
				continue;
			}
		}
		else if(a[i] > a[cnt]){
			if(c[i] == c[cnt]){
				a[i] -= a[cnt];
				cnt--;
				i--;
				continue;
			}
			else{
				a[i] -= a[cnt];
				ans += a[cnt];
				cnt--;
				i--;
				continue;
			}
		}
		else{
			if(c[i] == c[cnt]){
				a[cnt] -= a[i];
				continue;
			}
			else {
				a[cnt] -= a[i];
				ans += a[i];
				continue;
			}
		}
	}
	cout << ans;
	return 0;
}
