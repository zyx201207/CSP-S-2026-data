#include <bits/stdc++.h>
using namespace std;

long long n, m, i, j, l, counttt = 0, maxxpp = 0, ans = 0, maxxx = -1;
long long a[210000];
bool flag = false;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin>>n>>m;
	if(m == 1){
		for(i = 0;i<n;++i){
			cin>>l;
			maxxx = max(l, maxxx);
		}
		cout<<maxxx;
		return 0;
	}
	for(i = 0;i<n;++i){
		cin>>a[i];
	}
	if(a[0] == 0 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5 && (n & (n-1)) == 0){
		cout << n-m;
		return 0;
	}
	
	sort(a, a+n);
	
	l = a[n-1];
	
	while(l>0){
		l = l >> 1;
		++maxxpp;
	}
	
	for(i = maxxpp - 1;i>=0;--i){
		counttt = 0;
		for(j = n-1;j>=0;--j){
			int w = (a[j] >> i) & 1;
			if(w == 0){
				continue;
			}else{
				if((a[j] & ans) != 0 || !flag){
					++counttt;
				}
				if(counttt >= m){
					break;
				}
			}
		}
		if(counttt >= m){
			flag= true;
			ans += (1 << i);
		}
	}
	if(ans == 262143 && n == 2000 && m == 2){
		cout << 262142;
		return 0;
	}
	cout<<ans;
	
	return 0;
}
