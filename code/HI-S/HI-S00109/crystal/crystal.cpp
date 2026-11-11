#include <bits/stdc++.h>
using namespace std;

long long a[500001];

int main(){ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for (long long i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n);

	long long t = 1;
	long long maxn = 1;
	while (m){
		for (long long j = 1;j <= t;j++){
			if (a[t+1] - a[j] <= m){
				m -= a[t+1] - a[j];
				a[j] = a[t+1];
			}
		}
		t++;
	}
	for (long long i = 2;i <= n;i++){
		if (a[i] == a[i-1]){
			maxn++;
		}else {
			break;
		}
	}
	
	cout<<maxn;
	return 0;
}

