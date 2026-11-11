#include<bits/stdc++.h>
//long long
#define endl '\n';
using namespace std;

long long n,a[200050],l,r,ans;
char c[200050];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>> n;
	l = 1,r = n;
	for(long long i = 1;i <= n;i ++){
		cin >> a[i] >> c[i];
	}
	while(l < r){
		if(c[l] != c[r]){
			if(a[l] > a[r]){
				ans += a[r];
				a[l] -= a[r];
				r --;
			}
			else if(a[r] > a[l]){
				ans += a[l];
				a[r] -= a[l];
				l ++;
			}
			else{
				ans += a[l];
				l ++;r--;
			}
		}else{
			if(a[l] > a[r]){
				//ans += a[r];
				a[l] -= a[r];
				r --;
			}
			else if(a[r] > a[l]){
				//ans += a[l];
				a[r] -= a[l];
				l ++;
			}
			else{
				l ++;r--;
			}
		}
	}
	cout << ans;
	return 0;
}

