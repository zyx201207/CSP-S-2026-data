#include <bits/stdc++.h>
using namespace std;
int g, cnt=0, d;
int f(int n){
	if(n == 1)return 1;
	else if(n == 2)return 2;
	else if(n == 3)return 4;
	else if(n > 3 && n > d){
		int a=0;
		for(int i=n-d; i<n; i++){
			a += f(i);
		}
		return a;
	}
	else{
		int a=0;
		for(int i=1; i<n; i++){
			a += f(i);
		}
		
		return a;
	}
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int c, t, n, x[100000], pre[100000], sum=0;
	cin >> c >> t;
	t = 1;
	while(t--){
		sum = 0;
		cin >> n >> d;
		cin >> x[1];
		for(int i=2; i<=n; i++){
			cin >> x[i];
			pre[i] = x[i] - x[i-1];
			sum += pre[i];
		}
		g = ceil(sum / d) ;
		
	}
	return 0;
} 
