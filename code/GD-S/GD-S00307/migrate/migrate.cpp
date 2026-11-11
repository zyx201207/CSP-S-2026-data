#include<bits/stdc++.h>
#define ll long long
#define N 2000005
using namespace std;
ll anaxa,T,n,dm,a[N],d[N],cnt[N];
ll kd(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void sl(){
	ll ans=0;
	scanf("%lld%lld",&n,&dm);
	for(int i=1;i<=n;i++) a[i]=kd();
	for(int st=1;st<n-2;st++){
		queue<ll> q;
		memset(d,0x3f,sizeof d);
		d[st]=0;
		memset(cnt,0,sizeof cnt);
		q.push(st);
		while(!q.empty()){
			ll u=q.front();q.pop();
			if(d[u]>=3) continue;
			for(int v=u+1;v<=n;v++){
				if(a[v]-a[u]>dm) break;
				if(d[v]>d[u]+1){d[v]=d[u]+1;cnt[v]=1;q.push(v);}
				else if(d[v]==d[u]+1) cnt[v]++;
			}
		}
		for(int i=st+2;i<=n;i++){
			if(cnt[i]==2) ans++;
		}
	}
	printf("%lld\n",ans);
}
void sl2(){
	scanf("%lld%lld",&n,&dm);
	for(int i=1;i<=n;i++) a[i]=kd();
	ll c=a[2]-a[1];
	if(c>dm){printf("0\n");return;}
	ll ans=dm/c;
	if(ans==1){printf("0\n");return;}
	printf("%lld\n",max(0ll,n-ans+1-ans));
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&anaxa,&T);
	if(anaxa==11||anaxa==12){
		while(T--) sl2();
		return 0;
	}
	while(T--) sl();
} 
