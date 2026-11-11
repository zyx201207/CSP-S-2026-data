#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
long long n , a[N] , j , su;
string x;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		cin >> x[i];
	}
	for(int i = 0 , j = n - 1;i < j;){
		if(x[i] != x[j]){
			if(a[i] > a[j]){
				su += a[j];
				a[i] -= a[j];
				j--;
			}
			else if(a[i] < a[j]){
				su += a[i];
				a[j] -= a[i];
				i++;
			}
			else{
				su += a[i];
				i++; j--;
			}
			 
		}
	}
	cout << su;
	return 0;
}
