#include<bits/stdc++.h>
using namespace std;
long long cr[500005],aa[500005],ans=0,cnt=0,maxx=-10000,m,n;

long long csl(long long n,long long m){
	cr[0]=0;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&cr[i]);
		
	}
	sort(cr+1,cr+n+1);
	
	for(long long i=2;i<=n;i++){
		cnt+=(cr[i]-cr[i-1]);
		ans++;
		if(cnt>m){
			cnt=0;
			if(ans>maxx){
				maxx=ans-1;
			}
			ans=0;
		}
	}
	
	return maxx+1;
}
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	printf("%lld",csl(n,m));
	return 0;
	
}
