#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],iff,sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	//cout << n;
	//return 0;
	sort(a+1,a+1+n);
	for(long long i = 1;i<=m;i++){
		a[1]++;
		sort(a+1,a+1+n);
	}
	iff=a[1];
	for(int i = 1;i<=n;i++){
		if(iff==a[i]){
			sum++;
		}
	}
	cout << sum;
	return 0;
} 
