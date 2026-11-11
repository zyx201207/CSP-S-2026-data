#include <bits/stdc++.h>
using namespace std;
long long a[500005]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,ma=1;
	cin >> n >> m;
	for(int i=1;i <= n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i <= n;i++){
		long long nw=0;
		long long cnw=0;
		int j=i;
		while(j--&&nw <= m){
			long long c=0;
			c= a[i] -a[j];
			nw+=c;
			cnw++;
		}
		ma = max(ma,cnw);
	}
	cout <<ma;
	return 0;
}
