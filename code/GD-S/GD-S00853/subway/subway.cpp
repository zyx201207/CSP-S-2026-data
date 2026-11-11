#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,q,I;
ll w[500005];
ll tu[1005][1005];
ll xt[1005][1005];
bool yuan[1005];
bool lvis[1005];
ll x,y;
void speain(){
	ll s,e,t,l;
	for(int i=1;i<=n;i++){
		scanf("%lld",&I);
		scanf("%lld %lld",&s,&t);
		if(I==2){
			scanf("%lld %lld",&e,&l);
			if(tu[s][e]!=0){
				
			}
			tu[s][e]=t+l;
			tu[e][s]=t+l;
		}
	}
}
void xfwin(){
	ll t,s,e;
	for(int i=1;i<=n;i++){	
		vector<pair<ll,ll>> l;
		scanf("%lld",&I);
		for(int j=1;j<=I;j++){
			scanf("%lld %lld",&t,&e);
			l.push_back({t,e});
			for(int k=1;k<=l.size();k++){
				t+=l[k-1].first;
				s=l[k-1].second;
				tu[s][e]=t;
				tu[e][s]=t;
			}
		}
	}
}
void solve(){
	while(q--){
		memset(lvis,0,sizeof lvis);
		scanf("%lld %lld",&x,&y);
		if(!yuan[x]){
			ll s=x,cnt=1;
			xt[x][x]=0;
			while(cnt<=n){
				lvis[s]=1;
				for(int i=1;i<=n;i++){
					if(i==s)continue;
					if(tu[s][i]!=0){
						if(xt[x][i]==-1)xt[x][i]=xt[x][s]+tu[s][i];
						else xt[x][i]=min(xt[x][i],xt[x][s]+tu[s][i]);
					}
				}
				ll lg=-1,s=-1;
				for(int i=1;i<=n;i++){
					if(lvis[i])continue;
					if(lg==-1){
						s=i;
						lg=xt[x][i];
					}else{
						if(lg<xt[x][i]){
							lg=xt[x][i];
							s=i;
						}
					}
				}
				cnt++;
			}
			yuan[x]=1;
		}
		printf("%lld\n",xt[x][y]);
	}
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	if(c>=7||c<=11){
		speain();
	}else{
		xfwin();
	}
	solve();
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

