#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long a[N];
int main(){
   	freopen("and.in", "r", stdin);
   	freopen("and.out", "w", stdout);
	long long n, l;
	cin >> n >> l;
	for(int i =  1; i <= n; i++){
		cin >> a[i];
	}
    sort(a + 1, a + n + 1);
	long long sum = a[l];
    for(int i = l; i < n; i++){
		sum &= a[i];
	}
	cout << sum;
    return 0;
}
