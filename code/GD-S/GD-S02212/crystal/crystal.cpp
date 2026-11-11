#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long need[n+1]={};
	long long qian[n+1]={};
	qian[1]=a[1];
	for(int i=2;i<=n;i++){
		qian[i]=qian[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		need[i]=a[i]*i-qian[i];
	}
	for(int i=1;i<=n;i++){
		if(need[i]>m){
			cout << i-1;
			return 0;
		}
	}
	return 0;
} 
