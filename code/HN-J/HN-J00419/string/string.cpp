#include<bits/stdc++.h>
using namespace std;
long long n,kk,ll;
long long len,mid,ans; 
long long a[200005];
char c[200005]; 
long long gcd(long long xx,long long yy){
	if(yy==0) return xx;
	return gcd(yy,xx%yy);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) {
		scanf("%d %c",&kk,&c[i]);
		if(i==1) len=kk;
		len=gcd(len,kk);
		a[i]=a[i-1]+kk;
	}
	if(len!=1) for(long long i=1;i<=n;i++) a[i]/=len;
	mid=((a[n]-1)>>1 )+1;
	if(a[n]%2==1) mid--;
	
	for(long long i=1,j=1,k=n;j<=mid;j++){//len-j+1
		if(j==a[i]+1) i++;
		if(a[n]-j+1==a[k-1]) k--;
		if(c[i]!=c[k]) ans++;
		
	}
	
	cout<<ans*len;
	return 0;
}
