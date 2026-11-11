#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);	
	long long n,m,a[100005],maxfas;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	long long ro[100005];
	for (int i = 1;i <= n;i++){
		ro[i] = a[i + 1] - a[i];
	}
	for (int i = 1;i < n;i++){
		long long sum = 0,k = 0;
		while(sum < m && i + k < n){
			k++;
			sum = sum + (ro[i + k] * k);
		}
		maxfas = max(maxfas,k + 1);
	}
	cout << maxfas;
	return 0;
}
