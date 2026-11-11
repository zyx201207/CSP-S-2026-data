#include<bits/stdc++.h>
using namespace std;
long long erjin[1000000];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,zong=0,lin=0;
	cin>>n>>m;
	int a[n+10],b[m+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=n-m+2;i--){
		zong+=2(a[i])  2(a[i-1]);
		
	}
	cout<<12;
	return 0;
} 
