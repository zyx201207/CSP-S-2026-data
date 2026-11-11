#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N=1e6+10;
int c,T,n,k,vis[N],l,r,mid,tmp,mx1,mx2,ckr,vidx,vld[N],deg[N],tdeg[N],dep[N],q[N],qidx,cds[N],rt;
vector<int> road[N];
bool enb[N],buc[N],aft[N];
int dfs(int x,int f){
	if(buc[x])return 1;
	int cmx=0;
	for(auto& i:road[x]){
		if(i==f)continue;
		cmx=max(cmx,dfs(i,x));
	}
	return cmx+1;
}
int dfs2(int x,int f){ // return root below it
	int snc=0,trt=0,ret=0;
	for(auto& i:road[x]){
		if(i==f)continue;
		dep[i]=dep[x]+1;
		trt=dfs2(i,x);
		if(!trt)continue;
		mx1=max(mx1,dep[trt]-dep[x]-1);
		snc++,ret=trt;
	}
	if(snc>1 or buc[x])return x;
	return ret;
}
bool check(int alw){
	vidx++;
	memcpy(tdeg+1,deg+1,n<<2);
	qidx=rt=0;
	for(int i=1;i<=n;i++){
		cds[i]=n;
		buc[i]=enb[i]=aft[i]=false;
		if(tdeg[i]==1)q[++qidx]=i,cds[i]=alw;
	}

	for(int i=1,ti;i<=qidx;i++){
		ti=q[i];
		if(!cds[ti]){
			enb[ti]=buc[ti]=true;
			cds[ti]=2*alw+1;
			rt=ti;
		}
		for(auto& j:road[ti]){
			if(tdeg[j]==1)continue;
			
			cds[j]=min(cds[j],cds[ti]-1);
			tdeg[j]--;
			enb[j]|=enb[ti];
			if(tdeg[j]==1)q[++qidx]=j;
			break;
		}
	}
	if(!rt)return true;
	ckr=0;
	for(int i=1;i<=n;i++){
		ckr+=enb[i];
	}
	if(!buc[q[n]]){
		mx1=mx2=0;
		for(auto& i:road[q[n]]){
			tmp=dfs(i,q[n]);
			if(tmp>mx1)mx2=mx1,mx1=tmp;
			else if(tmp>mx2)mx2=tmp;
		}
		if(mx1+mx2>2*alw+1)return ckr-2*alw<=k;
	}
	mx1=0;
	dep[rt]=0;
	dfs2(rt,rt);
	// cout<<alw<<' '<<ckr<<' '<<mx1<<'\n';
	return ckr-min(2*alw,mx1)<=k;
}
void run(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		road[i].clear();
	}
	memset(deg+1,0,n<<2);
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		deg[x]++,deg[y]++;
		road[x].emplace_back(y);
		road[y].emplace_back(x);
	}
	if(k==n){
		cout<<0<<'\n';
		return;
	}
	if(n==2){
		cout<<1<<'\n';
		return;
	}
	l=1,r=n;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--)run();
}