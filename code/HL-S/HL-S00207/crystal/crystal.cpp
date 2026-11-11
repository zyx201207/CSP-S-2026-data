#include<bits/stdc++.h>
using namespace std;
long long a[500050];
long long b[500050];
long long c[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdin);
	long long n,m;	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	long long t=1;
	for(long long i=1;i<n;i++){
		c[i]=c[i-1]+b[i]*t;
		t++;
	}
	for(int i=1;i<=n;i++){
		if(c[i-1]>m){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
} 
/* 5 8
-3 -1 2 2 7
*/
