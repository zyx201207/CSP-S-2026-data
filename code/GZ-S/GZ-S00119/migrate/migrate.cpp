#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010,M=N*N;
ll S,T;
ll n,m;
ll a[N];
ll ans[N][N];
ll head[N],nxt[N],to[N],E;
void add(ll x,ll y){
	to[E]=y;
	nxt[E]=head[x];
	head[x]=E;
	E++;
}
int mp[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&S,&T);
	for(int scp=1;scp<=T;scp++){
		E=0;
		memset(head,-1,sizeof(head));
		memset(ans,0,sizeof(ans));
		memset(mp,0,sizeof(mp));
		scanf("%lld%lld",&n,&m);
	    for(int i=1;i<=n;i++){
		    scanf("%lld",&a[i]);
	    }
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>m){
					break;
				}
				add(i,j);
			}
		}
		for(int i=1;i<=n;i++){
			int q[N],hh=0,tt=-1;
			q[++tt]=i;
			while(hh<=tt){
				int t=q[hh];
				hh++;
				for(int j=head[t];j!=-1;j=nxt[j]){
					int k=to[j];
				//	printf("%lld %lld %lld %lld\n",i,k,ans[i][k],ans[i][t]);
					if(ans[i][k]==0){
						ans[i][k]=ans[i][t]+1;
						mp[i][k]++;
						q[++tt]=k;
					}
					else if(ans[i][t]+1==ans[i][k]){
						mp[i][k]++;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mp[i][j]==2){
					ans++;
				}
			//	printf("%lld ",mp[i][j]);
			}
		//	puts("");
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
