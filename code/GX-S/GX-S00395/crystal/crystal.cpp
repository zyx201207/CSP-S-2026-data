#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long n, a[6000000], v[6000000], c = -100, g = 0;
long long m;
bool nm(long long a, long long b){
	return a < b;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w+", stdout);
	cin >> n >> m;
	for(long long i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == i){
            g++;
		}
	}
	if(g == n){
        int kl = 0;
        for(long long i = 0; i < n && m > 0; i++){
            m -= i;
            kl++;
        }
    cout << kl;
	}
	sort(a, a + n, nm);
	for(long long i = n - 1; i >= 0; i--){
		long long u = m, d = 1, l = i, r = i;
		for(long long j = n - 1; j >= 0; j--){
			if(a[i] - a[l - 1] > u || a[1 + r] - a[r] > u || u <= 0){
				break;
			}
			else if(r + 1 >= n && u >= a[l] - a[l - 1]){
				u -= a[i] - a[l - 1];
				l--;
				d++;
			}
			else if(l - 1 < 0 && u >= d * (a[r + 1] - a[r])){
				u -= d * (a[r + 1] - a[r]);
				r++;
				d++;
			}
			else if(u >= min(a[i] - a[l - 1], d * (a[r + 1] - a[r]))){
                if(a[i] - a[l - 1] == min(a[i] - a[l - 1], d * (a[r + 1] - a[r]))){
                    l--;
                }
                else{
                    r++;
                }
                u -= min(a[i] - a[l - 1], d * (a[r + 1] - a[r]));
                d++;
			}
			else
                break;
		}
		c = max(c, d);
	}
	cout << c;
	return 0;
}
