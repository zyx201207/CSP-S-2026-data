#include<bits/stdc++.h>
using namespace std;

const int N=1e6,lg=19;

int tid,t;
int n,m;
int u[N+5],v[N+5];
vector<int> mp0[N+5];

int d0[N+5];
int fa0[N+5];

void dfs0(int x,int fx){
	d0[x]=d0[fx]+1;
	fa0[x]=fx;
	for(int i=0;i<mp0[x].size();++i){
		if(mp0[x][i]==fx){
			continue;
		}
		dfs0(mp0[x][i],x);
	}
	return;
}

int get_dp(int rt){
	dfs0(rt,0);
	int p=0;
	for(int i=1;i<=n;++i){
		if(d0[i]>d0[p]){
			p=i;
		}
	}
	return p;
}

int sq0[N+5],ln0;
int fg0[N+5];

void work1(){//get zhi jing (longest dis)
	int p1=get_dp(1);
	int p2=get_dp(p1);
	int x=p2;
	ln0=0;
	while(x!=0){
		sq0[++ln0]=x;
		x=fa0[x];
	}
	sq0[0]=0;
	sq0[ln0+1]=0;
	for(int i=1;i<=n;++i){
		fg0[i]=0;
	}
	for(int i=1;i<=ln0;++i){
		fg0[sq0[i]]=1;
	}
	return;
}

int mxd0[N+5];

int dfs1(int x,int fx){
	int rt=0;
	for(int i=0;i<mp0[x].size();++i){
		if(mp0[x][i]==fx || fg0[mp0[x][i]]==1){
			continue;
		}
		rt=max(rt,dfs1(mp0[x][i],x)+1);
	}
	return rt;
}

int pr[N+5],sf[N+5];
int X,Y,mi;

int cal(int l,int r){
	int rt=0;
	for(int i=1;i<=ln0;++i){
		rt=max(rt,mxd0[i]+min(abs(i-l),abs(i-r)));
	}
	return rt;
}

void work2(){//get sol of m=2 (only choose 2 points)
	for(int i=1;i<=ln0;++i){
		mxd0[i]=dfs1(sq0[i],0);
	}
	pr[0]=0;
	for(int i=1;i<=ln0;++i){
		pr[i]=max(pr[i-1],mxd0[i]);
	}
	sf[ln0+1]=0;
	for(int i=ln0;i>=1;--i){
		sf[i]=max(sf[i+1],mxd0[i]);
	}
	mi=n+1;
	X=0;
	Y=0;
	for(int i=1;i<=ln0;++i){
		for(int j=i+1;j<=ln0;++j){
			int ct=cal(i,j);
			if(ct<=mi){
				mi=ct;
				X=i;
				Y=j;
			}
		}
	}
	//cout<<X<<'='<<Y<<':'<<mi<<'\n';
	return;
}

int sq[N+5],ln;
vector<int> sd[N+5];
int mxd[N+5];
int fg[N+5];

int dfs2(int x,int fx,int id){
	int mx=0;
	for(int i=0;i<mp0[x].size();++i){
		if(mp0[x][i]==fx || fg[mp0[x][i]]==1){
			continue;
		}
		mx=max(mx,dfs2(mp0[x][i],x,id)+1);
	}
	while(mx>=sd[id].size()){
		sd[id].push_back(0);
	}
	++sd[id][mx];
	return mx;
}

int get_sd(int id,int lm){
	if(lm>=sd[id].size()){
		return 1;
	}
	return sd[id][lm];
}

int L[N+5],R[N+5];
int tg[N+5];

int ck(int lm){
	int rt=0;
	for(int i=1;i<=ln;++i){
		tg[i]=ln;
	}
	for(int i=1;i<=ln;++i){
		rt+=get_sd(i,lm);
		L[i]=max(i-max(lm-mxd[i],0),1);
		R[i]=min(i+max(lm-mxd[i],0),ln);
		tg[L[i]]=min(tg[L[i]],R[i]);
		//cout<<mxd[i]<<':'<<L[i]<<' '<<R[i]<<':'<<get_sd(i,lm)<<'\n';
	}
	int mx=0,r=ln;
	for(int l=ln-1;l>=1;--l){
		r=min(r,tg[l+1]);
		mx=max(mx,r-l-1);
	}
	//cout<<1<<'/'<<X<<'/'<<Y<<'/'<<ln0<<';'<<'\n';
	//cout<<lm<<'x'<<rt<<'/'<<mx<<'p'<<rt-mx<<'\n';
	return (rt-mx<=m);
}

int work3(){//expand 2 points to 2 components
	ln=0;
	for(int i=X;i<=Y;++i){
		sq[++ln]=sq0[i];
	}
	for(int i=1;i<=n;++i){
		fg[i]=0;
	}
	for(int i=1;i<=ln;++i){
		fg[sq[i]]=1;
		sd[i].clear();
	}
	//int ct=0;
	for(int i=1;i<=ln;++i){
		mxd[i]=dfs2(sq[i],0,i);
		/*for(int j=0;j<sd[i].size();++j){
			cout<<sd[i][j]<<'x';
		}
		cout<<'\n';*/
		for(int j=mxd[i]-1;j>=0;--j){
			sd[i][j]+=sd[i][j+1];
		}
		/*for(int j=0;j<sd[i].size();++j){
			cout<<sd[i][j]<<' ';
		}
		cout<<'\n';
		if(mxd[i]+1!=sd[i].size()){
			exit(1);
		}*/
		//ct+=sd[i][0];
	}
	int ans=n;
	for(int g=__lg(n);g>=0;--g){
		if(ans-(1<<g)>=0 && ck(ans-(1<<g))==1){
			ans-=(1<<g);
		}
	}
	return ans;
}

int solve(){
	for(int i=1;i<=n;++i){
		mp0[i].clear();
	}
	for(int i=1;i<n;++i){
		mp0[u[i]].push_back(v[i]);
		mp0[v[i]].push_back(u[i]);
	}
	work1();
	work2();
	if(m==2){
		return mi;
	}
	int rt=n;
	if(1ll*ln0*ln0*n*__lg(n)<=2e8){
		for(int i=1;i<=ln0;++i){
			for(int j=i+1;j<=ln0;++j){
				X=i;
				Y=j;
				rt=min(rt,work3());
			}
		}
	}
	else if(1ll*ln0*n*__lg(n)<=2e8){
		for(int i=1;i<=ln0;++i){
			for(int j=i+1;j<=ln0;++j){
				if(cal(i,j)!=mi){
					continue;
				}
				X=i;
				Y=j;
				rt=min(rt,work3());
			}
		}
	}
	else{
		rt=min(rt,work3());
		++X;
		rt=min(rt,work3());
		--X;
		--X;
		rt=min(rt,work3());
		++X;
		++Y;
		rt=min(rt,work3());
		--Y;
		--Y;
		rt=min(rt,work3());
		++Y;
	}
	return rt;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>tid>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;++i){
			cin>>u[i]>>v[i];
		}
		cout<<solve()<<'\n';
	}
	return 0;
}//answer ?pts
