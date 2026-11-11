#include <bits/stdc++.h>

using namespace std;
long long n,m,a[500005],ans,mm;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >>  m;
	for(int i = 1;i <= n;i++)
		cin >> a[i]; 
	if(n <= 5){
		for(int i = 1;i <= n;i++){
			int maxn = 0,sum = 0;
			for(int j = 1;j <= i + 1;j++){
				if(maxn < a[j]) maxn = a[j];
				sum += a[j];
			}	
			sum -= maxn;
		if(sum + m >= maxn * (i - 1)){
			for(int k = 1;k <= i-1;k++){
				ans += maxn - a[i] + 1;
		} 
		if(ans > mm) mm = ans; 
	}
	}
	}
	cout << mm;
	return 0;
}
