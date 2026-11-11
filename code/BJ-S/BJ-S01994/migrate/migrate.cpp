#include<bits/stdc++.h>
#define ll long long
using namespace std;
//const maxm=5e5+10;
const int maxn=2e6+10;
ll status;
FILE *fl;
ll c,t;
ll n,d;
ll pos[maxn];
namespace Q1val{
	ll nextg[5010];
}
void Q1(){
	using namespace Q1val;
	memset(nextg,0,sizeof(nextg));
	ll ans=0;
	//fprintf(stderr,"@@@");
	status=scanf("%lld%lld",&n,&d);
	for (ll i=1;i<=n;i++){
		status=scanf("%lld",pos+i);
	}
	for (ll i=1;i<=n;i++){
		ll l=i+1,r=n;
		ll tas=0;
		while(l<=r){
			ll mid=(l+r)/2;
			if (pos[mid]-pos[i]<=d){
				tas=max(tas,mid);
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		nextg[i]=tas;
		//fprintf(stderr,"(%lld,%lld)",i,tas);
	}
	for (ll s=1;s<n;s++){
		for (ll e=s+3;e<=n;e++){
			ll flag=1;
			//fprintf(stderr,"<%lld,%lld>",s,e);
			ll cnt=0;
			ll p=s;
			while(p<e){
				cnt++;
				p=nextg[p];
				//fprintf(stderr,"!%lld!",p);
				if (p==0){
					flag=0;
					break;
				}
			}
			if (!flag)continue;
			//fprintf(stderr,"(%d,%d,%d)",s,e,cnt);
			queue<pair<int,int>>q;
			map<pair<int,int>,int>mnp;
			q.push({s,0});
			mnp[{s,0}]=1;
			ll tts=0;
			while(q.size()){
				pair<int,int>u=q.front();
				q.pop();
				int tmp=mnp[u];
				mnp[u]=0;
				ll now=u.first,used=u.second;
				//fprintf(stderr,"(%lld,%lld)",now,used);
				if (now==e){
					tts+=tmp;
					continue;
				}
				for (ll i=now+1;i<=min(nextg[now],e);i++){
					ll newused=used+1;
					ll dis=pos[e]-pos[i];
					if (dis>d*(cnt-newused))continue;
					pair<int,int>newpair={i,newused};
					if (mnp[newpair]==0){
						q.push(newpair);
						mnp[newpair]=tmp;
					}else{
						mnp[newpair]+=tmp;
					}
				}
			}
			//fprintf(stderr,"(%d,%d,%d)",s,e,tts);
			if (tts==2){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	fl=freopen("migrate.in","r",stdin);
	fl=freopen("migrate.out","w",stdout);
	status=scanf("%lld%lld",&c,&t);
	while(t--){
		//fprintf(stderr,"%lld",t);
		Q1();
	}
	return 0;
}
