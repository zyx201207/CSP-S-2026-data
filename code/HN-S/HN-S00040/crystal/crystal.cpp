#include<bits/stdc++.h>
using namespace std;
long long a[5010000],b[5010000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(long long i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	long long ans = 0;
	long long mid,l = 0,r = n-1;
	while(1){
		mid = (l+r)/2;
		if(l >= r-1){
			break;
		}
		long long m2 = m;
		long long cnt = 0;
		for(long long i = 0;i < n;i++){
			b[i] = a[i];
		}
		for(long long i = 0;i < n;i++){
			b[i] = a[mid] - b[i];
		}
		sort(b,b+n);
		for(long long i = 0;i < n;i++){
			if(b[i] >= 0){
				m2 -= b[i];
				if(m2 < 0){
					r = mid;
					ans = max(cnt,ans);
					break;
				}
				cnt++;
			}
		}
		if(m2 >= 0){
			ans = max(cnt,ans);
			l = mid;
		}
		else{
			r = mid;
		}
	}
	
	cout << ans << endl;
	return 0;
} 
