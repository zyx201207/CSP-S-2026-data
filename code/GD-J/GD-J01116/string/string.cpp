#include <bits/stdc++.h>
#define i64 long long
using namespace std;
const int N = 2e5+5;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	int pl = 1, pr = n;
	i64 ans = 0;
	while(pl < pr){
		if(a[pl] <= a[pr]){
			if(c[pl] != c[pr]){
				ans += a[pl];
			}
			a[pr]-=a[pl];
			pl++;
			if(a[pr] == 0) pr--;
		} else{
			if(c[pl] != c[pr]){
				ans += a[pr];
			}
			a[pl]-=a[pr];
			pr--;
		}
	}
	cout << ans;
}
