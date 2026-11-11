#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long ct[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	for(long long i = 1;i < n;i++){
		b[i] = a[i + 1] - a[i];
		ct[i] = ct[i - 1] + b[i]; 
	}
	long long mx = 1;
	for(long long i = 1;i < n;i++){
		for(long long j = i + 1;j < n;j++){
			if(j - i + 1 <= mx){
				continue;
			}
			if(ct[j] - ct[i - 1] <= m){
				mx = max(mx,j - i + 1);
			}
		}
	}
	cout << mx + 1;
	return 0;
} 
