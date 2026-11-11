#include<bits/stdc++.h>
using namespace std;
long long n, ans, a[200001], m;
char c[200001];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		ans += a[i];
	}
	long long i = 1, j = n, num = 0, sum = ans / 2;
	while(num < sum){
        if(c[i] != c[j])
            m++;
        num++;
        a[i]--;
        a[j]--;
        if(a[i] == 0)
            i++;
        if(a[j] == 0)
            j--;
	}
	cout << m;
	return 0;
}
