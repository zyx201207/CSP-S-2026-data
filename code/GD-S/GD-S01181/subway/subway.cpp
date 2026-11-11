#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long a[2000010],n,d,ans = 0;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> t;
	for(int ll = 1;ll <= t;ll++){ 
		cin >> n >> d;
		ans = 0;
		if(n == 1){
			cout << "0";
		}
		else{
			for(int i = 1;i <= n;i++)cin >> a[i];
			long long k = a[2] - a[1];
			if(d > k){
				ans++;
				for(int i = 2;i <= n - 2;i++){
					ans += (n - i);
				}
			}
			cout << ans << endl;	
		}
	}	 
	return 0;
}
