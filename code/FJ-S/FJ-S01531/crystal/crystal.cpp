#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5;
long long a[N+1], q[N+1];	
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;
	bool f=0;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	q[1]=a[1];
	for(int i=1; i<=n; i++) {
		q[i]=q[i-1]+a[i];
	}
	for(int i=n; i>0; i--) {
		for(int j=0;j+i<=n;j++){
			if(q[j+i]-q[j-1]+m>=a[i+j]*i){
				cout<<i;
				f=1;
				break;
			}
		}
		if(f)break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
