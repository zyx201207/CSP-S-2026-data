#include <bits/stdc++.h>
using namespace std;
long long a[600005],b[600005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long u=1;
	for(int i=n;i>=1;i--){
//		cout<<b[i]<<" ";
		while(b[i]-b[i-u]+m>=a[i]*u&&i-u>=0){
			u++;
		}
//		cout<<m<<" ";
	}
	cout<<u-1;
	return 0;
}
/*
5 40
-100000 9 20 30 31
*/
