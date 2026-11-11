#include<bits/stdc++.h>
using namespace std;
long long n,cnt,a[1000005];
char b[1000005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
	}
	for(int i = 1; i <= n / 2; i++){
		if(b[i] != b[n - i + 1]){
			if(a[i] == a[n - i + 1]){
				cnt += a[i];
			}else if(n - i != i){
				a[n - i] -= 1;
				cnt += a[i];
			}else{
				cnt += a[n - i + 1];
			}
		}
	}
	cout << cnt;
	return 0;
} 
