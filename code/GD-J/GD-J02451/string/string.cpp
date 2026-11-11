#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 20;
long long a[N], b[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	char s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cin >> s;
		b[i] = s - 'a' + 1;
	}
	long long sum = 0;
	for(int i = 1; i <= n; ){
		if(b[i] == b[n]){
			if(a[i] > a[n]){
				a[i] -= a[n];
				n--;
			}else if(a[i] < a[n]){
				a[n] -= a[i];
				i++;
			}else{
				n--;
				i++;
			}
		}else{
			if(a[i] > a[n]){
				a[i] -= a[n];
				sum += a[n];
				n--;
			}else if(a[i] < a[n]){
				a[n] -= a[i];
				sum += a[i];
				i++;
			}else{
				sum += a[i];
				n--;
				i++;
			}
		}
	}
	cout << sum;
	return 0;
}
