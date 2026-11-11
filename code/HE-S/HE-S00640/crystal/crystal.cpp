#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	long long n,m,max;
	long long a[500001];
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	long long h = n/2;
	long long f = m;
	while(1){
		if (h==1){
			break;
		}
		long long f1 = a[h]-a[h-1];
		if (f >= f1){
			f -= f1;
			a[h-1] = a[h];
			h--;
		}else{
			break;	
		}
	}
	for (int i=1;i<=n;i++){
		if (a[i] == a[h]){
			max++;
		}
	}
	cout << max;
	return 0;
}
