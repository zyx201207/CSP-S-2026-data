#include<bits/stdc++.h>
using namespace std;
int const N=2e5+10;
long long n,a[N],ad[N],de;
long long p1,p2,ans,d1,d2;
char s[N],t1,t2;
int f( long long k,long long p,long long t){
	for(int i=p;i<=n&&i>=1;i+=t){
		if(k>ad[i-1]&&k<=ad[i])return i;
	}
	return n;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		scanf(" %c",&s[i]);
		ad[i]=ad[i-1]+a[i];
	}
	p1=1,p2=ad[n],t1=s[1],t2=s[n];
	d1=1,d2=n;
	while(p1<p2){
		long long de2=p2-ad[d2-1],de1=ad[d1]-p1+1;
		de=min(de1,de2);
		if(t1!=t2)ans+=de;
		p1+=de,p2-=de;
		d1=f(p1,d1,1),d2=f(p2,d2,-1);
		t1=s[d1],t2=s[d2];
	}
	printf("%lld",ans);
	return 0;
}
