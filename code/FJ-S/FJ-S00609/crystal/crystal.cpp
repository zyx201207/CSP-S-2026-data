#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long qzh[500010];
bool check(long long x){
	long long mins=1e18;
	for(int i=1;i+x-1<=n;i++){
		mins=min(mins,a[i+x-1]*x-(qzh[i+x-1]-qzh[i-1]));
	}
	return mins<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\crystal\\crystal4.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	long long l=1,r=n;
	while(l<=r){
		long long z=(l+r)>>1;
		if(check(z)){
			l=z+1;
		}else{
			r=z-1;
		}
	}
	cout<<l-1;
	return 0;
}