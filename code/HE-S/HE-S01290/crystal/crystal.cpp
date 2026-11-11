#include<bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5 + 5;
struct Node{
	long long b;
	long long cha; 
}a[N]; 

int main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	long long n, m;
	cin >> n >> m;
	
	for(long long i = 1; i <= n; i++){
		scanf("%lld", &a[i].b);
		a[i].cha = a[i].b - a[i - 1].b;
		//printf("%lld %lld\n", a[i].b, a[i].cha);
	}
	
	bool f1 = true;
	bool f2 = true;
	for(long long i = 1; i <= n; i++){
		if(a[i].cha != a[i - 1].cha && i > 2)f1 = false;
		if(a[i].b != i)f2 = false;
	}
	
	int t;
	int mi = INT_MIN;
	int q;
	if(f1){
		printf("%lld", n);
	}else if(f2) {
		for(long long i = 1; i <= n; i++){
			t = i + 1;
			if((1 + i) * i / 2 <= m && (1 + t) * t / 2 > m){
				printf("%lld", i);
				break;
			}
		}
	}
	return 0;
}
