#include<bits/stdc++.h>
using namespace std;
int n,m;
long long in[10000001],sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&in[i]);
	sort(in+1,in+1+n);
	for(int i=2;i<=n;++i){
		sum=0;
		for(long long len=1;len<=i;++len){
			sum+=in[i]-in[i-len];
			if(sum>m||len==i){
				if(ans<len) ans=len; 
				break;
			}
		}
	} 
	printf("%lld",ans);
	return 0;
} 
