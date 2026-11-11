#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long mid=(n+1)/2;
	cout<<mid+(m-1)/n;
	return 0;
} 
/*
6+5+4+3+2+1=21

10 25
1 2 3 4 5 6 7 8 9 10
x=7
1+6=7
m-=6=19
2+5=7
m-=5=14
3+4=7
m-=4=10

dp[i]=max(a[i],dp[i-1]+a[i])


*/
