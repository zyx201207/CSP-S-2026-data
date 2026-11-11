#include "bits/stdc++.h"
using namespace std;
long long n,m,a[200004];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=a[n];
	for(int i = n-1;i > n-m;i--){
		sum&=a[i];
		//cout<<a[i]<<' '<<sum<<endl;
	}
	cout<<sum;
}
