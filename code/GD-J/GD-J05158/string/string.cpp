#include<bits/stdc++.h>
using namespace std;
const int N=2e5+500;
int a[N],n;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}
	long long l=0,r=a[n],ls=1,rs=n;
	long long ans=0;
	while(ls<rs){
		int cha=min(a[ls]-l,r);
		if(c[ls]!=c[rs]){
			ans+=cha;
		}
		l+=cha;
		if(l>=a[ls]){
			ls++;
			l=0;
		}
		r-=cha;
		if(r<=0){
			rs--;
			r=a[rs];
		}
	}
	printf("%lld",ans);
	return 0;
} 
