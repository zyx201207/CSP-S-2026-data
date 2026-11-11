#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005],t = 0;
char c[200005];
bool f = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	long long r = n,m = n / 2,l = 1;
	for (int i = 1;i <= n - 1;i++){
		if(a[i] == a[i + 1]) {
			f = 1;
			continue;
		}
		else{
			t = 0;
			break;
		} 
	}
	if(f == 1){
		for (int i = 1;i <= m && r >= m + 1;i++){
			if(c[i] != c[r]){
				t += max(a[i],a[r]);
			}
			r--;
		}
	}
	else {
		t = 0;
	}
	cout << t;
	return 0;
}
