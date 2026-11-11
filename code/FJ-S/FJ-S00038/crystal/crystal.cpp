#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],l,r,sum;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(long long l=1,r=1,mid=0;r<=n;r++){
		mid+=(r-l)*(a[r]-a[r-1]);
		while(l<r&&mid>m)mid-=(a[r]-a[l++]);
		sum=max(sum,r-l+1ll);
//		cout<<l<<" "<<r<<" "<<mid<<"------\n";
	}
//	if(n==1)cout<<1;
	cout<<sum;
	return 0;
}/*
10 84
-40 -41 16 2 48 40 -26 24 -21 31
*/
