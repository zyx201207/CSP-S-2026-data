#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll oo=1e15;
int k,n,m,d,q;
ll w[500005],x,y,h[505][505],ans,s[505][505];
struct qq{
	int i;
	ll s;
	friend bool operator < (qq a,qq b){
		return a.s>b.s;
	}
}p;
vector<qq> u[500005];
vector<qq> l[505];
priority_queue<qq> t;
void dij(int x){
	for(int i=1;i<=n;i++)s[x][i]=oo;
	s[x][x]=0;
	t.push({x,0ll});
	while(!t.empty()){
		p=t.top();
		t.pop();
		if(p.s>s[x][p.i])continue;
		for(int i=0;i<l[p.i].size();i++){
			if(p.s+l[p.i][i].s<s[x][l[p.i][i].i]){
				s[x][l[p.i][i].i]=p.s+l[p.i][i].s;
				t.push({l[p.i][i].i,p.s+l[p.i][i].s});
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&k,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			h[i][j]=oo;
		}
		h[i][i]=0;
	}
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&x,&y);
			u[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int I=0;I<u[i].size();I++){
			for(int J=I+1;J<u[i].size();J++){
				h[u[i][I].i][u[i][J].i]=min(h[u[i][I].i][u[i][J].i],u[i][I].s+u[i][J].s);
				h[u[i][J].i][u[i][I].i]=h[u[i][I].i][u[i][J].i];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(h[i][j]<oo){
				l[i].push_back({j,h[i][j]});
				l[j].push_back({i,h[j][i]});
			}
		}
	}
	for(int i=1;i<=n;i++)dij(i);
	while(q--){
		scanf("%lld%lld",&x,&y);
		ans=oo;
		for(int i=0;i<u[x].size();i++){
			for(int j=0;j<u[y].size();j++){
				ans=min(ans,w[x]+u[x][i].s+s[u[x][i].i][u[y][j].i]+w[y]+u[y][j].s);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
