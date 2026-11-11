#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000005,inf=223456789000000000; 
ll qread(){
	ll rtn=0,fh=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')fh=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		rtn=rtn*10+c-'0';
		c=getchar();
	}
	return fh*rtn;
}
ll c,t,n,d,a[N],ry[N],ly[N],f[5005][5005],f2[5005][5005];
int main(){
	cin>>c>>t;
	a[0]=-inf;
	while(t--){
		cin>>n;
		a[n+1]=inf;
		for(int i=1;i<=n;i++){
			a[i]=qread();
		}
		int l,r; 
		for(l=1,r=2;l<=n;r++){
			while(a[r]-a[l]>d){
				ry[l]=r-1;
				l++;
			}
		}
		for(l=n-1,r=n;r>=1;l--){
			while(a[r]-a[l]>d){
				ly[r]=l+1;
				r--;
			}
		}
		
	}
	return 0;
} 
