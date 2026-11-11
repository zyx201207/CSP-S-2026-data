#include<bits/stdc++.h>
using namespace std;
vector<long long>a;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, sum = 0;
	cin >> n >> m;
	for(long long i = 0; i < n; i++){
		long long b;
		cin >> b;
		a.push_back(b);
		sum += b;
	}
	long long g = sum / n;
	long long sum1 = 0;
	for(long long i = 0; i < n; i++){
		if(a[i] > g){
			sum1 = sum1+(a[i] - g);
		}
		else{
		 sum1 = sum1+(g-a[i]);	
		} 
	}
	if(sum1 == m){
		cout << n;	
		return 0;
	}
	cout << m;
	return 0;
} 
