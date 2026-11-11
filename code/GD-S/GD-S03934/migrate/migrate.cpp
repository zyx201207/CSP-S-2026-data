#include<bits/stdc++.h>
using namespace std;
long long a[200007];

int cmp(long long x,long long y){
	return x > y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c, t;
	cin >> c >> t;
	long long sum = 0;
	while(t--){
		long long n, d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		} 
		sort(a+1,a+n+1);
		if(a[1] > 0){
			sum = (a[n]-a[1])/d;
		}else if(a[1] == 0){
			sum = 0;
		}else{
			sum = (a[n]+a[1])/d;
		}
		cout << sum << "\n";
		
	} 
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/ 
