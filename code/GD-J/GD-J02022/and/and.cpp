#include <bits/stdc++.h>
using namespace std;

bool cmp(int a , int b){
	return a > b;
}
int ret(int n , int k){
	int i = 1;
	int o[50] = {0};
	while(n > 0){
		o[50-i] = n % 2;
		n = n / 2;
		++i;
	}
	return o[49-k];
}
int main(){
	int s[100005] = {0};
	int a[50] = {0} , b[50] = {0};
	int h[200000] = {0};
	int n = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> s[i];
	}
	int flag = 0;
	for(int i = 0;i < n;i++){
		for(int j = i + 1;j < n;j++){
			for(int k = 0;k < 50;i++){
				a[k] = ret(i,k);
				b[k] = ret(j,k);
			}
			for(int r = 0;r < 50;r++){
				h[flag] += a[r] && b[r];
			}
			++flag;
		}
	}
	sort(h,h+20,cmp);
	cout << h[0];
	cout << 1;
	return 0;
}
