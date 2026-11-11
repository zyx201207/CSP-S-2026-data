#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
const int MAXN = 500000+20;
long long a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	long long ans = -1;
	if(n <= 5000 || m <= 100000000){
		sort(a+1,a+n+1);
		for(long long i = n; i >= 1; i--){
			long long tmp = 0, cnt = 1;
			for(long long j = i-1; j >= 1; j--){
				tmp += a[i] - a[j];
				if(tmp > m) break;
				cnt++;
			}
			ans = max(ans,cnt);
		}
		cout << ans;
	}else{
		long long d = a[2] - a[1];
		long long tmp = 0, cnt = 1;
		for(long long i = 1; i <= n; i++){
			tmp += d + (i-1)*d;
			if(tmp > m) break;
			cnt++;
		}
		cout << cnt; 
	}
	
	return 0;
}
