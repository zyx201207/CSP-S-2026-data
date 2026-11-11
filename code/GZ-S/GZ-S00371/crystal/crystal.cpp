//GZ-S00371
//遵义市新蒲新区滨湖中学
//邓佳琪 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n, m;
	cin >> n >> m;
	long long a[n + 5]; 
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	
	//二分区间 
	long long l = 1, r = n;
	
	while(l < r){
		long long min = (l + r + 1) / 2;
		
		bool t = false;
		
		for (long long i = 1;i <= n - min + 1; i ++){
			long long y = m;
			long long mx = i + min - 1;
			for (int j = i; j < mx; j ++){
				if (t || (j == mx - 1 && a[mx] - a[j] <= y)){
					t = true;
					break;
				}

				if (a[mx]- a[j] <= y){
					y -= (a[mx] - a[j]);
					continue;
				}
				else break;
			} 
			
			if (t) break;		
		}
		
		if(t){
			l = min;
		}else r = min - 1;
	}
	
	cout << l;
	return 0;
}

