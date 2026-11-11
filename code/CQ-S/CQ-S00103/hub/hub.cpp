#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,fa[200005],v[200005],p[200005],minn=0x3f3f3f3f3f3f3f3f,zc,kk[200005],cc[200005];
vector<long long> g[200005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
    	scanf("%lld%lld",&n,&k);
    	for(long long i=1;i<=n-1;i++){
    		long long x,y;
    		scanf("%lld%lld",&x,&y);
		}
		printf("%lld\n",n/k-1);
	}
    
	return 0;
}

