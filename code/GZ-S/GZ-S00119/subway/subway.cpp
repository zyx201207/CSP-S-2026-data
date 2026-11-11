#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=60010;
ll c,n,m,d,q;
ll head[N],nxt[N],to[N],w[N],E;
ll ac[N];
void add(ll x,ll y,ll c){
	w[E]=c;
	to[E]=y;
	nxt[E]=head[x];
	head[x]=E;
	E++;
}
ll ak[N];
struct str{
	int x,y;
}b[5000][5000];
str qu[N];
ll res[N];
ll bol[N],vs;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		scanf("%lld",&ac[i]);
	}
	for(int i=1;i<=n;i++){
		ll k;
		scanf("%lld",&k);
		ak[i]=k;
		for(int j=1;j<=k;j++){
			ll x,y;
			scanf("%lld%lld",&x,&y);
			b[i][j].x=x,b[i][j].y=y;
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&qu[i].x,&qu[i].y);
	}
	for(int i=1;i<=n;i++){
		 for(int j=2;j<=ak[i];j++){
		 	add(b[i][j].x,b[i][j-1].x,b[i][j].y+b[i][j-1].y);
		 	add(b[i][j-1].x,b[i][j].x,b[i][j].y+b[i][j-1].y);
		 }
	}
	for(int scp=1;scp<=q;scp++){
		for(int i=1;i<=m;i++){
			res[i]=1e18;
		}
		vs++;
		ll q[N],hh=0,tt=-1;
		ll ans=1e18;
	    q[++tt]=qu[scp].x;
	    while(hh<=tt){
	        ll t=q[hh];
	        printf("%lld %lld %lld\n",q[hh],q[tt],ans);
		    hh++;
		    for(int i=head[t];i!=-1;i=nxt[i]){
		    	ll j=to[i],k=w[i];
			    if(bol[j]==0&&j!=t){
			    	q[++tt]=j;
				}
				res[j]=min(res[j],res[t]+k);
				if(j==qu[scp].y){
					ans=min(ans,res[j]);
				}
		    }
	    }
	    printf("%lld\n",ans+ac[qu[scp].x]+ac[qu[scp].y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
