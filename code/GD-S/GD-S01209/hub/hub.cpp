#include<bits/stdc++.h>
using namespace std;
long long c,T,n,k;
void solve(){
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n-1;i++){
			long long u,v;
			scanf("%lld%lld",&u,&v);
		}
		long long l=n/2+1,t=k/2;
		if(k<n){
			long long t2=l/2;
			if(k==0)printf("%lld\n",l);
			else printf("%lld\n",max((long long)1,(t2-t)/2+1));
		}
		else printf("0\n");
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	if(13<=c&&c<=14){solve();}
	return 0;
} 
