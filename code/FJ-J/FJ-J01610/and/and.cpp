#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],maxx[200005];
int awy(int x,int y){
	int sum = 0,i = 0;
	while(x > 0 || y > 0){
		int ans = 1;
		for(int j = 1;j <= i;j++) ans *= 10;
		if(x % 10 == y % 10) sum += 1 * ans;
		else sum += 0 * ans;
	}
	return sum;
}
int ejz(int x){
	int sum = 0,i = 0;
	while(x > 0){
		int ans = 1;
		for(int j = 1;j <= i;j++) ans *= 10;
		sum += (x % 2) * ans;
		x /= 2;
		i++;
	}
	return sum;
}
int sjz(int x){
	int sum = 0,i = 0;
	while(x > 0){
		int ans = 1;
		for(int j = 1;j <= i;j++) ans *= 2;
		sum += (x % 10) * ans;
		x /= 10;
		i++;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a,a + n);
	for(int i = n;i >= n - m;i--) maxx[i + 1] = awy(ejz(a[i]),ejz(a[i + 1])); 
	cout << maxx[m - 1];
	return 0;
}

