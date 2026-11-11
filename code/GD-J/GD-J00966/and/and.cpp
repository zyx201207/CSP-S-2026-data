#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],s=0;
void f(long long x,long long k,long long d){
	if(k>m){
		s=max(s,x);
		return ;
	}
	for(int j=d+1;j<=n-m+k;j++){
		long long asd=x&a[j];
		f(asd,k+1,j);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n-m+1;i++){
		f(a[i],2,i);
	}
	cout<<s;
	
	return 0;
}
