#include<bits/stdc++.h>
using namespace std;
char c[20000086];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		long long u;char v;
		scanf("%lld %c",&u,&v);
		while(u--) c[++cnt]=v;
	}
	long long l=1,r=cnt,ans=0;
	while(l<=r){
		if(c[l]!=c[r]) ans++;
		l++;r--;
	}
	printf("%lld",ans);
	return 0;
}
