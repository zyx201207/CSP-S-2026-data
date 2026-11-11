#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=0;
long long llmax(long long x,long long y){
	if(x>=y) return x;
	else return y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		printf("%lld",ans);
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				long long t=1ll*(a[i]&a[j]);
				ans=llmax(ans,t);
			}
		printf("%lld",ans);
		return 0;
	}
	//sort(a+1,a+n+1);
	//n=unique(a+1,a+n+1)-a;
	for(int i=1;i<1<<n;i++){
		long long cnt=0,xz=0,t=i,s=0,op=1;
		while(t){
			++cnt;
			if(t&1){
				if(op){
					s=a[cnt];
					op=0;
				}
				else s=s&a[cnt];
				++xz;
			}
			t/=2;
		}
		if(xz==m) ans=llmax(ans,s);
	}
	printf("%lld",ans);
	return 0;
}
