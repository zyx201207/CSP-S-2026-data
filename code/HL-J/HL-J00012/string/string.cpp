#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct node{
	int n;
	char c;
}a[N];
long long n, ans;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].n >> a[i].c;
	}
	for(int i = 1, j = n; i <= j;){
		if(a[i].c != a[j].c){
			if(a[i].n < a[j].n){
				ans += a[i].n;
				a[j].n -= a[i].n;
				i++;
			}
			else if(a[i].n > a[j].n){
				ans += a[j].n;
				a[i].n -= a[j].n;
				j--;
			}
			else {
				ans += a[i].n;
				i++;
				j--;
			}
		}
		else{
			if(a[i].n < a[j].n){
				a[j].n -= a[i].n;
				i++;
			}
			else if(a[i].n > a[j].n){
				a[i].n -= a[j].n;
				j--;
			}
			else {
				i++;
				j--;
			}
		}
	}
	cout << ans;
	return 0;
}