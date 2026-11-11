#include <bits/stdc++.h> 
using namespace std;
long long c,t;
long long n,d;
long long a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	long long mm,ans;
	while (t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n;i++){
			int maxn = 0,sum = 0;
			for(int j = 1;j <= i + 1;j++){
				if(maxn < a[j]) maxn = a[j];
				sum += a[j];
			}	
			sum -= maxn;
		if(sum >= maxn * (i - 1)){
			for(int k = 1;k <= i-1;k++){
				ans += maxn - a[i] + 1;
		} 
		if(ans > mm) mm = ans; 
		ans= ans * (10 + 37);
		cout << ans << endl;
	}
	
	}
}
return 0;
}
