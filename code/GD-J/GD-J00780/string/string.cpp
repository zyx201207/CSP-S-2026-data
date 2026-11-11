#include<bits/stdc++.h>
char c;long n,a,l,r,I,ans,i,lp=1,rp;
struct o{long p;char c;}s[200002];
int main(){
	// freopen("string.in","r",stdin)
	// Luogu: zzd13
	freopen("string.in","r",stdin),
	freopen("string.out","w",stdout);
	for(scanf("%ld",&n);n--;)
		scanf("%ld %c",&a,&c),
		s[++I]={i+=a,c};
	r=i+1,rp=I;
	while(r-l>2){
		a=std::min(s[lp].p-l,r-s[rp-1].p-1);
		if(s[lp].c!=s[rp].c) ans+=a;
		l+=a,r-=a;
		if(l==s[lp].p) ++lp;
		if(r<=s[rp-1].p+1) --rp;
	}
	printf("%ld",ans);
}
