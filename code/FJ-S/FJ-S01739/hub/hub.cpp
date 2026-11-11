#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
inline void dd(int &x){
	x=0;
	char ch=getchar();int ff=1;
	while(ch>'9'||ch<'0'){
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+ch-'0',ch=getchar();
	}
	x*=ff;
}
const int N=1e6+5;
int n,dep[N],k,f[N],h[N],net[N*2],ver[N*2],tot=0,dl[N],len,md[N],g[N];
bool bl[N];
vector<int> LD,RD;
void add(int x,int y){
	++tot;
	ver[tot]=y;
	net[tot]=h[x];
	h[x]=tot;
}
void dfs1(int x,int fa){
	f[x]=fa;
	for(int i=h[x];i;i=net[i]){
		int y=ver[i];
		if(y==fa) continue;
		dep[y]=dep[x]+1;
		dfs1(y,x);
	}
}
int bfs(int x){
	for(int i=1;i<=n;++i) bl[i]=0;
	int l=0,r=0;
	dl[++r]=x,bl[x]=1;
	while(l<r){
		int x=dl[++l];
		bl[x]=1;
		for(int i=h[x];i;i=net[i]){
			int y=ver[i];
			if(bl[y]) continue;
			dl[++r]=y;
		}
	}
	return dl[r];
}
void dfs2(int x,int fa,int mid){
	f[x]=fa,dep[x]=dep[fa]+1,md[x]=1,g[x]=0;
	int fg=0;
	for(int i=h[x];i;i=net[i]){
		int y=ver[i];
		if(y==fa) continue;
		dfs2(y,x,mid);
		md[x]=max(md[x],md[y]+1);
		g[x]+=g[y];
		if(md[y]>=mid) fg=1;
	}
	if(fg) ++g[x];
}
bool check(int mid){
	int ls=0,rs=0,rx=len-mid,sum=2,mm=0;
	if(len<=mid*2+2) return 1;
	ls=mid+1,rs=ls+1,mm=rs;
//	cout<<"ncm"<<endl;
	for(int ttt=rs;ttt<rx;++ttt){
		int x=dl[ttt],fg=0;
		md[x]=1,g[x]=0;
		for(int i=h[x];i;i=net[i]){
			int y=ver[i];
			if(y==dl[ttt-1]||y==dl[ttt+1]) continue;
			dfs2(y,x,mid);
			md[x]=max(md[x],md[y]+1);
			g[x]+=g[y];
			if(md[y]>=mid) fg=1;
		}
		if(fg) ++g[x];
//		cout<<ttt<<" "<<x<<" "<<g[x]<<" "<<md[x]<<endl;
	}
	for(int i=rs;i<rx;++i)
		sum+=g[dl[i]]?g[dl[i]]:1;
	for(;ls<rx;++ls){
		while(!g[dl[mm]]&&md[dl[mm]]+mm-ls-1<=mid&&mm<rx) ++mm;
		while(!g[dl[rs]]&&(rs<mm||md[dl[mm]]+rs-mm-1)&&rs<rx) ++rs,--sum;
		if(sum<=k) return 1;
		if(rs==ls+1) ++rs;
		else ++sum;
		if(mm==ls+1) ++mm;
	}
	return 0;
}
void solve(){
	dfs1(1,0);
	int sl=bfs(1),sr=bfs(sl);
	LD.clear(),RD.clear();
	LD.pb(sl),RD.pb(sr); 
//	cout<<sl<<" "<<sr<<endl;
	while(sl!=sr){
		if(dep[sl]>=dep[sr]){
			sl=f[sl],LD.pb(sl);
		}else{
			sr=f[sr],RD.pb(sr);
		}
	}
	len=0;
//	for(int y:LD) cout<<y<<" "<<" ";
//	cout<<endl;
	for(int i=1;i<=(int)LD.size();++i) dl[++len]=LD[i-1];
	for(int i=RD.size()-2;i>=0;--i) dl[++len]=RD[i];
	dl[len+1]=dl[len+2]=0;
//	for(int i=1;i<=len;++i){
//		cout<<dl[i]<<" ";
//	}
//	cout<<endl;
	if(k==n) return printf("0\n"),void();
//	cout<<":aksl"<<endl;
//	cout<<"sakl"<<" "<<check(1)<<endl;
	int l=1,r=len;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	printf("%d\n",r+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int TT;
	dd(TT),dd(TT);
	while(TT--){
		tot=0;
		for(int i=1;i<=n;++i) h[i]=0,dep[i]=0,f[i]=0;
		dd(n),dd(k);
		for(int i=1,x,y;i<n;++i){
			dd(x),dd(y);
			add(x,y),add(y,x);
		}
		solve();
	}
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
