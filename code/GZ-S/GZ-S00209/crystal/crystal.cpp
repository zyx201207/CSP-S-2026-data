//GZ-S00209 黄琨淇 安顺市实验学校 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500010],n,m;
void bl(){
	sort(a+1,a+n+1,greater<ll>());
	for(int i = 1;i <= n;i++){
		ll cnt = 0;
		for(int j = i+1;j <= n;j++){
			cnt += a[i] - a[j];
		}
		if(cnt <= m){
			cout << n - i + 1;
			return;
		}
	}
}
void tAB(){
	ll cnt = 0,k = a[2] - a[1];
	for(int i = 1;i <= n;i++){
		cnt += i * k;
		if(cnt > m){
			cout << i;
			return;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool fl = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i >= 3 && a[i] - a[i-1] != a[i-1] - a[i-2])fl = 1;
	}
	if(fl)bl();
	else tAB();
	return 0;
}
