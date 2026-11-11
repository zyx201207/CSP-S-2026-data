#include<bits/stdc++.h>
using namespace std;
long long n, a[500005], maxn = 1;
unsigned long long x, m;
long long l = 1, cnt;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin >>n >> m;
    for (long long i = 1; i <= n; i ++){
        cin >>a[i];
    }
    sort(a + 1, a + n + 1);
    for (long long i = 2; i <= n; i ++){
        x += (a[i] - a[i - 1]) * (i - l);
        while(l < i && x > m){
            x -= a[i] - a[l];
            l ++;
        }
        maxn = max(maxn, i - l + 1);
    }
    cout << maxn;
	return  0;
}


