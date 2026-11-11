#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,a[N],i = 1,j;
long long ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	j = n;
	for(int k = 1;k <= n;k ++){
		cin >> a[k] >> c[k];
	}
	for(;i <= j;){
		if(c[i] == c[j]){
			if(a[i] > a[j]){
				a[i] -= a[j --];
			}
			else if(a[i] < a[j]){
				a[j] -= a[i ++];
			}
			else{
				i ++;
				j --;
			}
		}
		else{
			if(a[i] > a[j]){
				ans += a[j];
				a[i] -= a[j --];
			}
			else if(a[i] < a[j]){
				ans += a[i];
				a[j] -= a[i ++];
			}
			else{
				ans += a[i];
				i ++;
				j --;
			}
		}
	}
	cout << ans;
	return 0;
}
