#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char s[200010];
long long ans = 0;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> s[i];
	}
	int k = n;
	for(int i = 1;i <= n;i++){
		int m = a[i];
		if(k == i){
			break;
		}
		while(true){
			if(s[i] != s[k]){
				if(m - a[k] >= 0){
					m -= a[k];
					ans += a[k];
					a[k] = 0;
					k--;
				}
				else{
					a[k] -= m;
					a[i] = 0;
					ans += m;
					m = -1;
				}		
			}
			else{
				if(m - a[k] >= 0){
					m -= a[k];
					a[k] = 0;
					k--;
				}
				else{
					a[k] -= m;
					a[i] = 0;
					m = -1;
				}					
			}
			if(m <= 0){
				break;
			}			
		}
	}
	cout << ans ;
	return 0;
}
