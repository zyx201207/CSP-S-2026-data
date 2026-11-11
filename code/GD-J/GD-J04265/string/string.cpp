#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
long long cnt;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i] >> c[i];
	}
	int i = 1;
	int j = n;
	int rlen = 0;
	while(i < j){
		int ai = a[i];
		while(ai > 0){
			if(c[i] != c[j]){
				if(ai < a[j] - rlen){
					rlen += ai;
					cnt += ai;
					ai = 0;
				}
				if(ai == a[j] - rlen){
					rlen = 0;
					ai = 0;
					cnt += a[j] - rlen;
					j--;
				}
				if(ai > a[j] - rlen){
					ai -= a[j] - rlen;
					rlen = 0;
					cnt += a[j] - rlen;
					j--;
				}
			}else if(c[i] == c[j]){
				if(ai < a[j] - rlen){
					rlen += ai;
					ai = 0;
				}
				if(ai == a[j] - rlen){
					rlen = 0;
					j--;
					ai = 0;
				}
				if(ai > a[j] - rlen){
					ai -= a[j] - rlen;
					rlen = 0;
					j--;
				}
			}
		}
		++ i;
	}
    cout << cnt;
	return 0;
} 
