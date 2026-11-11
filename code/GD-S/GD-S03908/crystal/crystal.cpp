#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	long long n = 0,m = 0;
	long long xiao = 10000,k = 0,jia = 0,cnt = 0;
	cin >> n >> m;
	long long a[n+5];
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort (a,a+n);
	long long zhong = (a[0] + a[n-1]) / 2;//ÖÐ¼äÊý 
	for (int i = 0; i < n; ++i){
		if (abs(a[i] - zhong) < xiao) {
			xiao = abs(a[i] - zhong);
			k = a[i];
		}
		else break;
	}
	for (int i = 0; i < n; ++i){
		if (a[i] + m < k){
			continue;
		}
		while (a[i] < k){
			if (jia <= m){
				a[i]++;
				jia++;
			}
			else break;
		}
		if (a[i] == k) cnt++;
	}
	cout << cnt;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
