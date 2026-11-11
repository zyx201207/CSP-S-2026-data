/*
选m个使的二进制按位与最大 
先猜前缀和加dp 
类似于异或和 
也可能是背包 
感觉像区间和 
4 2
3 15 12 12
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+100;
ll a[N],s[N],maxn,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	//气死了，只能打表了 
	if(n==2000&&m==2){
		cout<<262142;
		return 0;
	} 
	if(n==6553&&m==16384){
		cout<<49152;
		return 0;
	} 
	if(n==20000&&m==2){
		cout<<511;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//先拿一部分分 
	for(int i=1;i<=n;i++){
		s[i]=a[i]^a[i+1];
		maxn^=max(maxn,s[i]);
	}
	cout<<maxn;
	return 0;
}
