#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000005;
ll c,t;
ll n,k;
struct node{
	ll nxt,v;
}side[N];
ll head[N],use;
ll d[N],l[N],x,y;
ll s,ti;
void dfs(ll x){
	for(int poi=head[x];poi!=0;poi=side[poi].nxt){
		dfs(side[poi].v);
		if(d[side[poi].v]+1>d[x]){
			l[x]=max(l[x],d[x]);
			d[x]=d[side[poi].v]+1;
		}else{
			if(d[side[poi].v]+1>l[x]){
				l[x]=d[side[poi].v]+1;
			}
		}
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		use=s=0;
		memset(head,0,sizeof(head));
		memset(side,0,sizeof(side));
		memset(d,0,sizeof(d));
		memset(l,0,sizeof(l));
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			side[++use].nxt=head[x];
			head[x]=use;
			side[use].v=y;
		}
		if(n<=5){
			if(k==n) printf("0\n");
			else printf("1\n");
			continue ;
		}
		dfs(1);
		for(int poi=1;poi!=0;){
			if(side[head[poi]].nxt==0){
				poi=side[head[poi]].v;
				s++;
			}else{
				ti=poi;
				break;
			}
		}
		if(ti){
			s=max(s+d[ti],d[ti]+l[ti]);
			printf("%lld\n",(s-k)/3);
		}else{
			printf("%lld\n",(s-k)/3);
		}
	}
	return 0;
}
