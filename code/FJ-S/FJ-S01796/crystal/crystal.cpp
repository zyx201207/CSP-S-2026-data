#include<bits/stdc++.h>
using namespace std;

long long a[500010];

bool cmp(long long a,long long b){
	return a > b;
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1,cmp);
	long long mans = 0,nans = 0,sum = 0,nm = 0;
	for (int i = 1;i <= n - 1;i++){
		nans = 1;
		sum = 0;
		nm = a[i];
		for (int j = i + 1;j <= n;j++){
			if (nm - a[j] <= m - sum){
				sum += nm - a[j];
				nans++;
			}
			else break;
		}
		if (nans > mans) mans = nans;
	}
	if (mans == 0) mans = 1;
	cout << mans;
	return 0;
} 
