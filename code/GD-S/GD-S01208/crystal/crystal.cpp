#include<bits/stdc++.h>
using namespace std;
long long a[500050],n,m;
bool f(long long intx){
	long long cnt = 0,inti = a[intx];
	for(int i = 1 ; i <= intx ; i++){
		cnt += inti - a[i];
	}
	if(cnt <= m) return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	long long l = 1 , r = n , intx;
	while(l <= r){
		long long mid = (l + r) / 2;
		if(f(mid)){
			intx = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	while(a[intx] == a[intx + 1]){
		intx++;
	}
	cout << intx;
} 
