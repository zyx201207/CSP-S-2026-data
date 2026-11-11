#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
using std::cin;using std::cout;
using std::string;using std::vector;
using std::max;using std::min;
const int N=1e6+10;
namespace zyh{
	struct node{
		int to,nxt;
	}edge[N<<1];
	int head[N];
	int cnt;
	void add(int u,int v){
		edge[++cnt]={v,head[u]};
		head[u]=cnt;
	} 
	int n,k,d1,d2;
	int dep[N];
	void dfs1(int x,int lst){
		dep[x]=dep[lst]+1;
		for(int i=head[x];i!=-1;i=edge[i].nxt){
			if(edge[i].to==lst) continue;
			dfs1(edge[i].to,x);
		}
	}
	vector<int> trd/*直径的点集 */,trdv,premxd,revmxd;
	bool vst[N];
	bool dfs2(int x,int lst){
		if(x==d2) return 1;
		for(int i=head[x];i!=-1;i=edge[i].nxt){
			if(edge[i].to==lst) continue;
			if(dfs2(edge[i].to,x)){
				trd.push_back(x);
				vst[x]=1;
				return 1;
			}
		}
		return 0;
	}
	int dfs3(int x,int lst){
		int res=0;
		for(int i=head[x];i!=-1;i=edge[i].nxt){
			if(vst[edge[i].to]||edge[i].to==lst) continue;
			res=max(res,dfs3(edge[i].to,x)+1);			
		}
		return res;
	}
	int ans;
	void work(){
		cin>>n>>k;
		for(int i=1;i<=n;i++) head[i]=-1;
		for(int i=1;i<n;i++){
			int uu,vv;
			cin>>uu>>vv;
			add(uu,vv),add(vv,uu);
		}
		//求直径 
		d1=d2=0;
		int tmp=0;
		for(int i=1;i<=n;i++) dep[i]=0;
		dfs1(1,0);
		for(int i=1;i<=n;i++){
			if(dep[i]>tmp){
				tmp=dep[i];
				d1=i;
			}
		}
		for(int i=1;i<=n;i++) dep[i]=0;
		dfs1(d1,0);
		for(int i=1;i<=n;i++){
			if(dep[i]>tmp);
			tmp=dep[i];
			d2=i;
		}
		trd.push_back(d2);
		dfs2(d1,0);
		trd.push_back(d1);
		vst[d1]=vst[d2]=1;
		if(k==2){//两点一定在直径上 
			int dlen=trd.size();
			trdv.resize(dlen),premxd.resize(dlen),revmxd.resize(dlen);
			for(int i=0;i<dlen;i++){
				int tmp=dfs3(trd[i],0);
				premxd[i]=max(i,tmp),revmxd[i]=max(dlen-1-i,tmp);
			}
			for(int i=dlen-2;i>=0;i--) revmxd[i]=max(revmxd[i],revmxd[i+1]+1);
			for(int i=1;i<dlen;i++) premxd[i]=max(premxd[i],premxd[i-1]+1);
			ans=n;
			for(int i=1;i<dlen;i++) ans=min(ans,max(revmxd[i],premxd[i-1]));
			cout<<ans<<'\n';
			return;
		}
	}
	int c,t;
	signed lqr(){
		cin>>c>>t;
		while(t--) work();
		return 0;
	}
}
void IO_set(string str){
	string s1=str+".in",s2=str+".out";
	freopen(s1.c_str(),"r",stdin);
	freopen(s2.c_str(),"w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
}
signed main(){
	IO_set("hub");
	return zyh::lqr();
}
