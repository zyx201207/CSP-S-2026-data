#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
ll n, m, a[N], b[N], sum, sum2;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = abs(a[i] - a[i - 1]);
		sum += a[i];
		sum2 += i;
	}
	sort(b + 1 , b + 1 + n);
	if(b[1] == b[n]) { //A,B
		int k = 0;
		while(m >= k) k++ , m -= k * b[1];
		cout << k;
		return 0;
	}
	return 0;
}
//30pts£¿ 
