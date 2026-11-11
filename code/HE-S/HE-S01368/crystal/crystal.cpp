#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000000];
bool cmp(long long x,long long y){
	return x < y;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i]; 
	}
	int cnt = 0;
	sort(a+1,a+n+1,cmp);
	int len = n % 2 ? n / 2 + 1 : n / 2;
	for(int i = len-1;i >= 1;i--){
		if(m - (a[len] - a[i]) >= 0){
			m -= (a[len] - a[i]);
			a[i] = a[len];
		}else{
			break;
		}
	}
	cout << '\n';
	for(int i = 1;i <= n;i++){
		if(a[i] == a[len]){
			cnt ++; 
		} 
	}
	cout << cnt ;
	return 0;
}
