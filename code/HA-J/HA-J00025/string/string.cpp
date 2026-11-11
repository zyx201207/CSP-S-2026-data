//freopen!!
//freopen±ğÍüÉ¾×¢ÊÍ 
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
long long n, a[200005];
char c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		if(i > 1 && c[i] == c[i - 1]){
			a[i - 1] += a[i];
			i--;
			n--;
		}
	}
//	for(int i = 1;i <= n;i++){
//		cout << a[i] << ' ' << c[i] << '\n';
//	}
	long long an = n, ans = 0;
	long long i = 1, j = an;
	while(i < j){
		//cout << i << ' ' << j << '\n';
		if((a[i] != a[j]) || (c[i] != c[j])){
			if(c[i] == c[j]){
				a[i + 1] -= abs(a[i] - a[j]);
				ans += abs(a[i] - a[j]);
				i++;
				j--;
				continue;
			}
			if(a[i] == a[j]){
				ans += a[i];
				i++;
				j--;
				continue;
			}
			if(a[i] < a[j]){
				a[j] -= a[i];
				ans += a[i];
				i++;
			}else{
				a[i] -= a[j];
				ans += a[j];
				j--;
			}
		}else{
			i++;
			j--;
		}
	}
	cout << ans;
	return 0;
} 
