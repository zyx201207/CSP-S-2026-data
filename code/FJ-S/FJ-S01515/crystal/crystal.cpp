#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum=0,num=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		a[i]++;
		sum++;
		if(sum>m) {
			break;
		}
		if(a[i]==a[i+1]) {
			num++;
		}
	}
	cout<<num;
	return 0;
}
