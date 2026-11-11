#include <bits/stdc++.h>
using namespace std ;
const long long  N =5e5+10;

long long n,m,a[N];
long long b[N];
 
int  main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long  i =1 ;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	for(long long  i =1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		
	}
	
	long long  cur=1;
	
	for(long long  i=1;i<=n;i++){
		while(cur+1<=i && a[i]*(cur+1)-(b[i] - b[i-(cur+1)])<=m){
			cur++;
		}
		
		
	}
	cout<<cur<<'\n';
	
} 
