#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+10;
long long a[maxn],sum[maxn];
int f(int m,int p){
	long long i,ans=0;
	for(i=1;i>=p;i++){
		long long ne=a[p]*(p-1); 
		if(m<0) break;
	} 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	long long n,i,m;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	cout<<max(f(n,n/2),f(m,n/2+1));
	return 0;
}
