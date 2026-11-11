#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct wyt{
	ll lj,tt;
};
struct dj{
	ll u,tm;
	bool operator<(const dj &a)const{
		return tm>a.tm;
	}
};
vector<wyt> g[505],lol[200005];
ll c,n,m,d,q,twt[200005],dist[200005];
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void dij(int st,int ed){
	priority_queue<dj> q;
	q.push({st,0});
	while(!q.empty()){
		dj p=q.top();
		if(p.u==ed){
			cout<<p.tm<<'\n';
			return ;
		}
		q.pop();
		for(int d=0;d<lol[p.u].size();d++){
			wyt nnn=lol[p.u][d];
			ll cccc=nnn.tt;
			for(ll i=0;i<g[nnn.lj].size();i++){
				ll cost=0;
				wyt nex=g[nnn.lj][i];
				if(nex.lj!=nnn.lj)cost=nex.tt;
				for(int j=0;j<g[nex.lj].size();j++){
					ll ccc=0;
					if(g[nex.lj][j].lj!=nex.lj)ccc=g[nex.lj][j].tt;
					if(dist[g[nex.lj][j].lj]>p.tm+ccc+cost+cccc){
						dist[g[nex.lj][j].lj]=p.tm+ccc+cost+cccc;
						q.push({g[nex.lj][j].lj,p.tm+ccc+cost+cccc});
					}
				}
			}
		}
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(ll i=1;i<=m;i++)twt[i]=read();
	for(ll i=1;i<=n;i++){
		ll k;
		k=read();
		for(ll j=1;j<=k;j++){
			ll a,t;
			a=read();
			t=read();
			g[i].push_back({a,t});
			lol[a].push_back({i,t});
		}
	}
	/*for(int i=1;i<=m;i++){
		cout<<i<<'\n';
		for(int j=0;j<lol[i].size();j++){
			cout<<"     "<<lol[i][j]<<'\n';
		}
	}*/
	/*for(int i=1;i<=n;i++){
		cout<<i<<'\n';
		for(int j=0;j<gg[i].size();j++)cout<<"    "<<gg[i][j]<<'\n';
	}*/
	for(ll i=1;i<=q;i++){
		ll l,r;
		memset(dist,127,sizeof(dist));
		l=read();
		r=read();
		dij(l,r);
	}
	return 0;
}
