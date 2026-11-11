#include<bits/stdc++.h>

using namespace std;

long long n,m,a[500005];

bool check(long long x){
	long long cnt = 0;
	for(long long i=1;i<=n;i++){
		if(a[i]<x){ 
			cnt += x - a[i];
		}
	}
	if(cnt<=m){
		return 1;
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	
	sort(a+1,a+1+n);
	
	long long sum = 0;
	long long l = a[1];
	long long r = a[n];
	
	while(l<r){
		long long mid = ( l + r + 1 ) / 2;
		if(check(mid)){
			l = mid;
		}
		else{ 
			r = mid - 1;
		}
	}
	for(long long i=1;i<=n;i++){
		if(r>=a[i]){ 
			sum++;
		}
	}
	cout << sum <<endl;
	return 0;
}
