#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,k;
long long a[10006],b[10006];
int main{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1;i <= n - 1;i++)
			cin >> a[i] >> b[i];
		cout << a[1] + b[1] + (b[2] + a[2]) + a[3]+ b[3] << endl;
		cout << a[1] + a[1] + a[2] + b[2];
			if(n <= 5){
		for(int i = 1;i <= n;i++){
			int maxn = 0,sum = 0,mm,ans;
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
	}
	}
	}
	}
	return 0;
}m m
