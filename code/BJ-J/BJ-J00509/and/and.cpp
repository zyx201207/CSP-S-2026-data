#include<bits/stdc++.h>
using namespace std;
int pd(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	long long a[n+5];
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n,pd);
	long long now = a[1];
	for(long long i = 2;i<=m;i++){
		now = now & a[i];
	}
	
	cout<<now;
	return 0;
}
