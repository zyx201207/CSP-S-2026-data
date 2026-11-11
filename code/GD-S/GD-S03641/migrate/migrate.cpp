#include<bits/stdc++.h>
#define ll long long
#define N 10000009
using namespace std;
ll x[N],l[N],r[N],cnt,in[N];
ll head[N],tot,dian[2000009][4];
struct edge{ll to,nxt,val;}e[N<<1];
void add(ll y,ll x,ll z){
	e[++tot].to=y,e[tot].val=z,e[tot].nxt=head[x],head[x]=tot;
}
queue<ll>q;
ll ans[N];
void work(ll s1,ll t1,ll val,ll i,ll id){
	if(s1>t1){
		add(dian[i][id],dian[i+1][id-1],val);
		in[dian[i][id]]++;
		return;
	}
	else if(t1-s1+1>=3)add(dian[i][id],dian[t1-2][3],val);
	else if(t1-s1+1==2)add(dian[i][id],dian[t1-1][2],val);
	else add(dian[i][id],dian[t1][1],val);
	in[dian[i][id]]++;
}
void topu(){
	for(ll i=1;i<=cnt;i++)
		if(in[i]==0)q.push(i);
	while(!q.empty()){
		ll now=q.front();
		q.pop();
		for(ll i=head[now];i;i=e[i].nxt){
			ll t=e[i].to;
			in[t]--;
			ans[t]+=ans[now]+e[i].val;
			if(in[t]==0)q.push(t);
		}
	}
}
void solve(){
	for(ll i=1;i<=cnt;i++)head[i]=ans[i]=in[i]=0;
	cnt=tot=0;
	ll n,d;
	scanf("%lld%lld",&n,&d);
	for(ll i=1;i<=n;i++)scanf("%lld",&x[i]);
	for(ll i=1;i<=n;i++){
		l[i]=i+1;
		ll now=l[i]-1;
		while(now+1<=n&&x[now+1]-x[i]<=d)now++;
		r[i]=now;
	}
	for(ll i=1;i<=n;i++)dian[i][1]=++cnt,dian[i][2]=++cnt,dian[i][3]=++cnt;
	for(ll i=n-1;i>=1;i--){
		ll s1=l[i],t1=r[i],s2=l[i+1],t2=r[i+1],s3=l[i+2],t3=r[i+2];
		if(s1<=t1)work(s1,t1,0,i,1);
		else continue;
		if(i+1>=n)continue;
		if(s2<=t2){
			if(t1>i+1)work(t1+1,t2,t1-(s1+1)+1,i,2);//²»Ëãi+1 
			else{
				add(dian[i][2],dian[i+1][1],0);
				in[dian[i][2]]++;
			}
		}
		else continue;
		if(i+2>=n)continue;
		if(s3<=t3){
			if(t1>i+2&&t2>i+2)work(t2+1,t3,t2-t1,i,3);
			else{
				add(dian[i][3],dian[i+1][2],0);
				in[dian[i][3]]++;
			}
		}
	}
	topu();
	ll Ans=0;
	for(ll i=1;i<=n;i++){
		ll now=dian[i][1];
		Ans+=ans[now];
	}
	printf("%lld\n",Ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*
0 1
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
*/
