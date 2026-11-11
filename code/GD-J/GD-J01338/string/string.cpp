#include<bits/stdc++.h>
using namespace std;
constexpr int N=200005;
int n,a[N];char c[N];
long long len,r,z;
int ri,rp;
void left(int s,char cc){
	while(s){
		int t=min(s,rp);
		if(c[ri]!=cc)z+=t;
		s-=t,rp-=t,r-=t;
		if(!rp)--ri,rp=a[ri];
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
		len+=a[i];
	}r=len,ri=n,rp=a[n];
	len=(len+1)/2;
	for(int i=1;i<=n;i++){
		if(r-a[i]<len){
			left(r-len,c[i]);
			break;
		}left(a[i],c[i]);
	}
	printf("%lld",z);
	return 0;
}
