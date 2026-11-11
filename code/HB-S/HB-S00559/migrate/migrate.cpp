#include <cstdio>
long long all[2000001];
int dp[5001],head,tail,extent;
long long ways[2000001],wayspref[200001];
void solve(){
    int n,ans=0;
    long long d;
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;++i){
	scanf("%lld",all+i);
    }
    for(int u=1;u<=n;++u){
	dp[u]=0ll;ways[u]=1ll;wayspref[u-1]=0ll;wayspref[u]=1ll;
	head=u,tail=u+1,extent=u+1;
	for(int v=u+1;v<=n;++v){
	    for(;head<tail&&all[v]-all[head]>d;++head);
	    if(head>=tail) break;
	    if(head>=extent)
		for(extent=head;extent<=tail&&dp[extent]==dp[head];++extent);
	    dp[v]=dp[head]+1ll;
	    ways[v]=wayspref[extent-1]-wayspref[head-1];
	    if(ways[v]==2ll) ++ans;
	    wayspref[v]=wayspref[v-1]+ways[v];
	    ++tail;
	}
    }
    printf("%d\n",ans);
}
long long max(long long a,long long b){
    return a>b?a:b;
}
void sp1solve(){
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++) scanf("%lld",&all[i]);
    long long para=d/(all[2]-all[1]);
    if(para<=1ll){
	printf("0\n");
	return ;
    }
    
    printf("%lld\n",max(0,n-(2*para-1)));
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    scanf("%d%d",&c,&T);
    if(c==11||c==12)
	while(T--) sp1solve();
    else
	while(T--) solve();
}
