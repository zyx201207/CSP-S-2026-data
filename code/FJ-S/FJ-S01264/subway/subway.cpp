#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read(){
	char ch=getchar();
	ll f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=(ll)(ch-'0');
		ch=getchar();
	}
	return f*x;
}

struct point{
	ll w,lin[501];
};

struct lines{
	ll a,t;
};

ll c,n,m,d,q;
point p[50010];
ll k[500010];
vector<lines> line[550];
ll vis[550][550];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		p[i].w=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			ll g,h;
			g=read(),h=read();
			p[g].lin[i]=j;
			line[i].push_back({g,h});
		}
	}
	
	while(q--){
		ll x,y;
		x=read(),y=read();
		ll ans=-1;
		for(int i=1;i<=n;i++){
			if(p[x].lin[i]!=0&&p[y].lin[i]!=0){
				ll ti=p[x].w+p[y].w+line[i][p[x].lin[i]].t+line[i][p[y].lin[i]].t;
				ans=max(ans,ti);
			}
		}
		if(ans!=-1) {
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}