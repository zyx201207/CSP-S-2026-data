#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q;
ll t[500009];
map<ll,ll> mp[509];
map<ll,ll> tt[509];
map<ll,ll> mpp[509];
map<ll,ll> a[500009];
ll di[500009];
ll b[509];
ll k[509];
bool v[500009][509];
struct node{
	ll t,st,li;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>t[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>mp[j][i];
			cin>>tt[mp[j][i]][i];
			mpp[mp[j][i]][i]=j;
			b[mp[j][i]]++;
			a[mp[j][i]][b[mp[j][i]]]=i;
		}
	}
	while(q--){
		ll fr,tO;
		cin>>fr>>tO;
		memset(v,0,sizeof v);
		memset(di,0x3f3f3f3f,sizeof di);
		queue<node> qu;
		for(ll i=1;i<=b[fr];i++){
			qu.push({fr,t[fr]+tt[fr][a[fr][i]],a[fr][i]});
			di[fr]=min(di[fr],t[fr]+tt[fr][a[fr][i]]);
			v[fr][a[fr][i]]=1;
		}
		ll ans=0x3f3f3f3f;
		while(qu.size()){
			node p=qu.front();
			qu.pop();
			if(p.t==tO){
				ans=min(ans,p.st+tt[tO][p.li]+t[tO]);
				continue;
			}
			for(ll i=2;i<=b[p.t];i++){
				ll li=a[p.t][i];
				ll nx=mpp[p.t][li];
				if(!v[p.t][li]||p.st+tt[p.t][li]+tt[p.t][p.li]<di[p.t]){
					qu.push({mp[nx][li],p.st+tt[p.t][li]+tt[p.t][p.li],li});
					di[p.t]=p.st+tt[p.t][li]+tt[p.t][p.li];
					v[p.t][li]=1;
				}
			}
			ll nx=mpp[p.t][p.li]+1;
			ll nx1=mpp[p.t][p.li]-1;
			if(nx<=k[p.li]&&(!v[mp[nx][p.li]][p.li]||p.st<di[mp[nx][p.li]])){
				qu.push({mp[nx][p.li],p.st,p.li});
				di[mp[nx][p.li]]=p.st;
				v[mp[nx][p.li]][p.li]=1;
			}
			if(nx1>=1&&(!v[mp[nx1][p.li]][p.li]||p.st<di[mp[nx1][p.li]])){
				qu.push({mp[nx1][p.li],p.st,p.li});
				di[mp[nx1][p.li]]=p.st;
				v[mp[nx1][p.li]][p.li]=1;
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
