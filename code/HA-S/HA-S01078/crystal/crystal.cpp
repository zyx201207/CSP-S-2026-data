#include<bits/stdc++.h>
using namespace std;
#define lli long long
namespace fastio{
	template <typename t>void read(t &n){
		t x=0,f=1;char c=' ';
		for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
		for(;isdigit(c);c=getchar()) x=x*10+c-'0';
		n=x*f;
	}
}using namespace fastio;
lli a[6666666];
lli b[6666666];
int n;lli m;lli sum=0;lli ans=1;
int main(){
	freopen(cin,"r",crystal.in);
	freopen(cout,"w",crystal.out);
	read(n);read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	lli cnt=0;
	for(int i=2;i<=n;i++){
		if(i==2){
			cnt=b[1];
		}else{
			cnt+=(i-1)*b[i];
		}
		if(cnt>m){
			printf("%d",i-1);
			return 0;
		}
	}
	return 0;
}

