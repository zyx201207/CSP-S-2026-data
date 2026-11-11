#include<bits/stdc++.h>

#define fr(i,l,r) for(int i=(l);i<=(r);i++)
#define fo(i,l,r) for(int i=(l);i<(r);i++)
#define fd(i,r,l) for(int i=(r);i>=(l);i--)

#define VI vector<int>
#define pub push_back
#define pob pop_back

#define PI pair<int,int>
#define fir first
#define sec second

using namespace std;

int Tid;

const int N=1e6+5;

int n,K,Ans;
VI nxt[N];

int ban[N],fa[N],dep[N];
int ans[N];

int S;
void dfs(int x){
	if(dep[x]>dep[S])S=x;
	for(int y:nxt[x]){
		if(y==fa[x]||y==ban[x])continue;
		fa[y]=x;
		dep[y]=dep[x]+1;
		dfs(y);
	}
	return;
}

int dfs2(int x){
	int mx=0;
	for(int y:nxt[x]){
		if(y==fa[x]||y==ban[x])continue;
		fa[y]=x;
		mx=max(mx,dfs2(y)+1);
	}
	ans[0]++;ans[mx+1]--;
	return mx;
}

void find(int x){
	S=x;fa[x]=dep[x]=0;dfs(x);
	fa[S]=dep[S]=0;dfs(S);
	int tmp=dep[S]+1;
	while(dep[S]*2>tmp)S=fa[S];
	if(dep[S]*2==tmp){
		fa[fa[S]]=S;
		tmp=max(dfs2(S),dfs2(fa[S]));
		ans[tmp+1]++;
	}
	else{
		fa[S]=0;
		ans[dfs2(S)+1]++;
	}
	return;
}

void calc(int rt1,int rt2){
	ban[rt1]=rt2;
	ban[rt2]=rt1;
	fr(i,0,n)ans[i]=0;
	find(rt1);find(rt2);
	fr(i,1,n)ans[i]+=ans[i-1];
	fr(i,0,n)if(ans[i]<=K){
		Ans=min(Ans,i);
	}
	ban[rt1]=ban[rt2]=0;
	return;
}

vector<PI>qwq;

void Main(){

	fr(i,1,n){
		nxt[i].clear();
		ban[i]=0;
	}
	qwq.clear();

	cin>>n>>K;
	fr(i,1,n-1){
		int x,y;
		cin>>x>>y;
		nxt[x].pub(y);
		nxt[y].pub(x);
	}
	Ans=n;

	if(Tid<=10){
		fr(i,1,n){
			for(int j:nxt[i])if(j<i){
				calc(i,j);
			}
		}
	}
	else{
		S=1;dfs(1);
		fa[S]=dep[S]=0;dfs(S);
		int tmp=(dep[S]+1)>>1;
		while(S!=0){
			if(abs(dep[S]-tmp)<=10){
				if(fa[S]!=0)qwq.push_back({S,fa[S]});
			}
			S=fa[S];
		}
		while(!qwq.empty()){
			int x=qwq.back().fir;
			int y=qwq.back().sec;
			qwq.pop_back();
			calc(x,y);
		}
	}

	cout<<Ans<<"\n";

	return;
}

int main(){

	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	ios::sync_with_stdio(false),cin.tie(nullptr);

	cin>>Tid;
	int Test=1;
	cin>>Test;
	while(Test--)Main();

	return 0;
}
