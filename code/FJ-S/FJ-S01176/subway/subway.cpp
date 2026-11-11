#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[1600005];
struct edg{
	int t,nex,w;
}e[2000005];
int hd[1500005];
int ct=0;
void add(int s,int t,int w){
	e[++ct].t=t;
	e[ct].w=w;
	e[ct].nex=hd[s];
	hd[s]=ct;
}
struct que{
	int s,t,d;
	que(){
	}
	que(int ss,int tt,int dd){
		s=ss,t=tt,d=dd;
	}
}qe[100005];
priority_queue<pair<int,int> > q;
int dis[1600005];

int co[2000005];
int bk[100005];//K
vector<pair<int,int> > pv[2005];//station
int f[1600005];
int ans[300005];
bool cmp(que a,que b){
	return a.s<b.s;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,qq;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&qq);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	int cnt=m+n;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		bk[i]=k;
		for(int j=1;j<=k;j++){
			int p,v;
			scanf("%lld%lld",&p,&v);
			pv[i].push_back({p,v});
		}
	}
	for(int i=1;i<=n;i++){
		int k=bk[i];
		for(int j=1;j<=k;j++){
			++cnt;
			int p=pv[i][j-1].first,v=pv[i][j-1].second;
			add(cnt,m+i,v);add(m+i,cnt,v);
			add(cnt,p,0);add(p,cnt,0);
		}
	}
	for(int i=1;i<=cnt;i++)dis[i]=1e9;
	for(int i=1;i<=qq;i++){
		int s,t;
		scanf("%lld%lld",&s,&t);
		qe[i]=que(s,t,i);
	}
	sort(qe+1,qe+1+qq,cmp);
	int lp=-1;
	for(int i=1;i<=qq;i++){
		int st=qe[i].s;
		dis[st]=0;
		q.push({0,st});
		memset(f,0,sizeof f);
		while(!q.empty()){
			pair<int,int> pe=q.top();
			q.pop();
			int v=-pe.first,s=pe.second;
			if(f[s])continue;
			f[s]=1;
			for(int i=hd[s];i;i=e[i].nex) {
				int t=e[i].t,pw=e[i].w;
			
				if(dis[t]>=dis[s]+pw){
					dis[t]=dis[s]+pw;
						
					q.push({-dis[s]-pw,t});
				}
			}
		}
		if(lp==-1)lp=st;
		while(lp==qe[i].s){
			ans[qe[i].d]=dis[qe[i].t]+w[st]+w[qe[i].t];
			i++;
		}
		lp=-1;i--;
		for(int i=1;i<=cnt;i++)dis[i]=1e9;
		
	}
	for(int i=1;i<=qq;i++){
		printf("%lld\n",ans[i]);
	}
}

