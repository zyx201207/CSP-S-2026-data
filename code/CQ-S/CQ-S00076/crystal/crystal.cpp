#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long k=0,p=1,c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')p*=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*p;
}
void putt(long long x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)putt(x/10);
	putchar(x%10+'0');
} 
const long long N=1e6+5;
long long n,m,a[N],s[N];
unsigned long long d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	a[0]=0;
	long long t=0,t1=0;
	for(long long i=1;i<=n;i++){
		a[i]=read();
		if(i>2&&a[i]-a[i-1]==a[i-1]-a[i-2]) t1++;
		else t1=0;
		if(a[i]==i){
			t++;
		}else{
			t=0;
		}
	}
	if(t==n){
		for(long long i=0;;i++){
			long long p=i*(i+1)/2,q=(i+1)*(i+2)/2;
			if(p<=m&&q>m){
				putt(i+1);
				return 0;
			}
		}
	}
	if(t1>=n-3){
		long long di=a[3]-a[2];
		if(di<0)
			di=-di;
		for(long long i=1;;i++){
			long long shou=(i-1)*di;
			long long p=shou*i/2,q=(shou+di)*(i+1)/2;
			if(p<=m&&q>m){
				putt(i);
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		s[i]=0;
	}
	for(long long i=1;i<=n;i++){
		long long sum=0;
		for(long long j=i+1;j<=n;j++){
			sum+=d[j]*(j-i);
			if(sum<=m){
				s[i]=max(j-i+1,s[i]);
			}
		}
	}
	long long ans=1; 
	for(long long i=1;i<=n;i++){
		ans=max(s[i],ans);
	}
	putt(ans);
	return 0;
}
