#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long q[200005];
long long n,m;
long long erjing(long long x)  {
	int s=0,j=1;
	while(x>0){
		s+=(x%2)*j;
		x/=2;
		j*=10;
	}
	return s;
}
long long fan(long long k){
	long long c=0,r=0;
	while(k>=0){
		c+=(k%10)*pow(2,r);
		k/=10;
		r++;
	}
	return c;
}
long long  check(long long a,long long b){
	long long wei;
	long long ti=a;
	long long da;
	while(ti>0){
		ti/=10;
		wei++;
	}
	for(int i=1;i<=wei;i++){
		if(a%10==1&&b%10==1)  da+=1*pow(2,i);
		a/=10;
		b/=10; 
	}
	return da;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxn=0;
	for(int i=1;i<=n;i++){
		a[i]=erjing(a[i]);
	}
	sort(a+1,a+n+1);
	long long lpl=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			long long y;
			if(j==1) y=check(a[i-1],a[i]);
			else  y=check(q[i-1],a[i]);
			lpl=fan(y);
			if(y>maxn) maxn=y;
			q[i]=q[i-1]+a[i];
			i++;
		}
	}
	long long ans=fan(maxn);
	cout<<ans;
	return 0;
}
