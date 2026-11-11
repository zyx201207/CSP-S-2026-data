//GZ-S00287,贵阳市第十七中学 ，周承瑞 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000000005];

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	if(n==0) {
		cout << 0;
	}
	long long x = n;
	for(long long i=0;i<n;i++){
		cin >> a[i];
		if(n <= a[i]&&n > 1){
			x-=1;
		}

}
if(x > m+1) cout << m;
 else cout << x;
	return 0;
}
