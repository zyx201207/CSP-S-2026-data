#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
long long a[N], b[N];
bool v = true;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	sort(a, a+n);
	for(int i = 0; i <= n; i++){
		if(a[i]==a[i+1]){
			continue;
		}else{
			v=false;
		}
	}
	if(v){
		cout<<n;
		return 0;
	}
	for(int i = 0; i <= n; i++){
		b[i] = abs(a[i+1] - a[i]);
	}
	long long sum = 0, cnt=0;
	for(int i = 0; i <= n; i++){
		if(sum <= m){
			sum += b[i];
		}else{
			cout<<i;
			return 0;
		}
	}
	return 0;
} 
