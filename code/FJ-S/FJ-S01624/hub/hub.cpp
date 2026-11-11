#include<bits/stdc++.h>
#define GP pair<int,int>
#define MP make_pair
using namespace std;int read();
const int N=1000005;
int n,m,D;
int fa[N],col[N],dep[N],sn[N],tp[N];
int dfl[N],dfr[N],dfnt,ori[N];
int mxd[N],mxid[N],myd[N];
vector<int> v[N],g[N];
int ft[N];GP gt[N];
int maxdep(int t,int ex){
	return (ex==mxid[t])?myd[t]:mxd[t];}
void dfs(int t){
	col[t]=1;
	mxd[t]=myd[t]=0,mxid[t]=0;
	vector<int> V;
	for(auto i:v[t]){
		if(fa[t]==i) continue;
		fa[i]=t,dep[i]=dep[t]+1;
		dfs(i);
		V.emplace_back(i);
		int w=mxd[i]+1;
		if(w>=mxd[t]){myd[t]=mxd[t];mxd[t]=w,mxid[t]=i;}
		else{myd[t]=max(myd[t],w);}
		col[t]+=col[i];
		if(col[i]>=col[sn[t]]) sn[t]=i;
	}v[t]=V;
}
void dfss(int t,int pt){
	tp[t]=pt;dfl[t]=++dfnt;ori[dfnt]=t;
	if(sn[t]) dfss(sn[t],pt);
	for(auto i:v[t]) if(i!=sn[t]) dfss(i,i);
	g[dep[t]].emplace_back(dfl[t]);dfr[t]=dfnt;
}
int LCA(int x,int y){
	while(tp[x]!=tp[y]){
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		x=fa[tp[x]];
	}return (dep[x]<dep[y])?x:y;
}
int Query(int t,int d){
	if(dep[t]==d) return t;
//	cout<<"query "<<t<<' '<<d<<'\n';
	int l=lower_bound(g[d].begin(),g[d].end(),dfl[t])-g[d].begin();
	int r=upper_bound(g[d].begin(),g[d].end(),dfr[t])-g[d].begin()-1;
	if(l>r) return 0;
//	cout<<ori[g[d][l]]<<' '<<ori[g[d][r]]<<'\n';
	return LCA(ori[g[d][l]],ori[g[d][r]]);
}
int QuerY(int t,int ex,int d){
	if(dep[t]==d) return t;
	//cout<<"query "<<t<<' '<<ex<<' '<<d<<'\n';
	//cout<<dfl[t]<<' '<<dfr[t]<<' '<<dfl[ex]<<' '<<dfr[ex]<<'\n';
	//for(auto i:g[d]) cout<<" "<<i; cout<<'\n';
	int l=lower_bound(g[d].begin(),g[d].end(),(dfl[t]+1==dfl[ex])?(dfr[ex]+1):dfl[t])-g[d].begin();
	int r=upper_bound(g[d].begin(),g[d].end(),(dfr[ex]==dfr[t])?(dfl[ex]-1):dfr[t])-g[d].begin()-1;
	//cout<<l<<' '<<r<<'\n';
//	if(l>r) exit(0);
	if(l>r) return 0;
	return LCA(ori[g[d][l]],ori[g[d][r]]);
}
int k,dp[N];GP cup[N];
GP upd(GP x,GP y){
	if(x.first<y.first) swap(x,y);
	return MP(x.first,max(x.second,y.first));
}
void dfs2(int t,GP cb){
	dp[++k]=t;
	ft[t]=Query(t,dep[t]+D-1);
	cb=upd(cb,cup[k]);
	for(auto i:v[t]){
		int nxd=max(0,D-1-maxdep(t,i));GP orr;
		GP db;db=cb;dp[k+1]=i;
		if(nxd==0) db=upd(db,MP(k,0));
		else if(k+nxd<=n){
			orr=cup[k+nxd];
		cup[k+nxd]=upd(cup[k+nxd],MP(k,0));
	}
		int pt=dp[db.first];
		if(!db.first){
			gt[i]=MP(0,0);
		}else if(db.second){
			gt[i]=MP(pt,pt);
		}else{
			//cout<<"st"<<db.first<<' '<<(D-1)<<' '<<k-db.first<<'\n';
			gt[i]=MP(QuerY(pt,dp[db.first+1],db.first+(D-1)-(k-db.first)),pt);
		}
		dfs2(i,db);
		if(nxd && k+nxd<=n)
			cup[k+nxd]=orr;
	}
	cup[k--]=MP(0,0);
}
int resA[N],resBU[N],resBD[N];
void dfs4(int t){
	for(auto i:v[t]){
		dfs4(i);
		resA[t]+=resA[i];
		resBU[t]+=resBU[i];
		resBD[t]+=resBD[i];
	}
}
int check(){
	//if(D>16) return 1;
	//if(D<16) return 0;
	if(D==0) return (m==n);
	for(int i=1;i<=n;i++){
		ft[i]=resA[i]=resBU[i]=resBD[i]=dp[i]=0;gt[i]=cup[i]=MP(0,0);
	}k=0;dfs2(1,MP(0,0));
//	cout<<"check "<<D<<'\n';
//	for(int t=1;t<=n;t++){
//		cout<<setw(5)<<ft[t]<<' '<<gt[t].first<<','<<gt[t].second<<'\n';}
	for(int t=1;t<=n;t++){
		int cnt=(!!gt[t].first);
		for(auto i:v[t]) cnt+=(!!ft[i]);
//		cout<<cnt<<' ';
		if(cnt<=1){
			resA[t]=1;
		}else if(cnt==2){
			for(auto i:v[t]){
				if(ft[i]){resBD[ft[i]]++,resBD[t]--;}}
			if(gt[t].first){
				resBU[t]++,resBU[gt[t].second]--;
				resBD[gt[t].first]++,resBD[gt[t].second]--;
			}
		}
	}//cout<<'\n';
	dfs4(1);
	for(int i=2;i<=n;i++){
		int cnt=0;
	//	cout<<resBD[i]+resA[1]-resA[i]<<' '<<resBU[i]+resA[i]<<' ';
		cnt+=max(1,n-col[i]-(resBD[i]+resA[1]-resA[i]));
		cnt+=max(1,col[i]-(resBU[i]+resA[i]));
	//	cout<<i<<' '<<' '<<n-col[i]<<' '<<col[i]<<' '<<' '<<cnt<<' '<<m<<'\n';
		if(cnt<=m) return 1;
	}//cout<<D<<' '<<"failed\n";
	return 0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C=read();int T=read();while(T--){
		n=read();m=read();
		for(int i=1;i<=n;i++){
			v[i].clear();g[i].clear();
			dep[i]=fa[i]=col[i]=0;
			dfl[i]=dfr[i]=sn[i]=0;
			cup[i]=gt[i]=MP(0,0);
		}
		for(int i=1;i<n;i++){
			int x=read();int y=read();
			v[x].emplace_back(y);
			v[y].emplace_back(x);
		}dfnt=0,dep[1]=1;dfs(1);dfss(1,1);
		int L=0,R=n;
		while(L<R){
			D=(L+R)>>1;
			if(check()) R=D;
			else L=D+1;
		}printf("%d\n",R);
	}
	return 0;
}
int read(){
	int Ca=0,Cf=1;char Cr=' ';
	while(Cr<'0' || Cr>'9'){Cr=getchar();if(Cr=='-'){Cf=-Cf;}}
	while(Cr>='0' && Cr<='9'){Ca=Ca*10+(Cr-'0');Cr=getchar();}
	return Ca*Cf;
}
