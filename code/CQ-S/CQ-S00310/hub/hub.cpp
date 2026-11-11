#include <bits/stdc++.h>
using namespace std;
int ccc,t,n,m,u,v,dep[1000010],kl[100010][20];
vector<int> e[1000010];
void dd(int id,int fa){
	dep[id]=dep[fa]+1,kl[id][0]=fa;
	for(int i=1;i<20;i++) kl[id][i]=kl[kl[id][i-1]][i-1];
	for(int i=0;i<e[id].size();i++){
		int to=e[id][i];
		dd(to,id);
	}
	return ;
}
int lca(int x,int y){
	if(x==y) return x;
	if(dep[x]>dep[y]) swap(x,y);
	int op=abs(dep[x]-dep[y]),cc=0;
	while(op){
		if(op&1) y=kl[y][cc];
		op/=2,cc++;
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(kl[x][i]!=kl[y][i]) x=kl[x][i],y=kl[y][i];
	}
	return kl[x][0];
}
int len(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void dfs(int id,int fa,int deep){
	
}
bool check(int cv){
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>ccc>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
		}
		dd(1,0);
//		if(m==2){
//			int l=1,r=n;
//			while(l<r){
//				int mid=(l+r)/2;
//				if(check(mid)) l=mid+1;
//				else r=mid;
//			}
//			cout<<l;
//		}
		int ub=1e9;
		for(int i=0;i<(1<<n);i++){
			vector<int> v;
			for(int j=0;j<n;j++){
				if(i&(1<<j)) v.push_back(j+1);
			}
//			cout<<i<<endl;
			if(v.size()==m){
//				for(int ii=0;ii<v.size();ii++) cout<<v[ii]<<" ";
//				cout<<endl;
				int nm=0;
				for(int ii=1;ii<=n;ii++){
					int gh=1e9;
					for(int jj=0;jj<v.size();jj++){
						gh=min(gh,len(ii,v[jj]));
					}
					nm=max(nm,gh);
				}
				ub=min(ub,nm);
			}
		}
		cout<<ub<<endl;
	}
	return 0;
}
/*
S组实在太急了，现在才写日志：
14:24 巴蜀大大很友好 
14:30 嘟嘟嘟
14:33 DUDUDU
14:35 大力敲键盘 
14:36 大大们都AC了，吓哭了 
14:40 T1挂了
14:51 T1AC了
15:00 T2屎
15:10 会建图了
15:23 会优化了
15:33 写代码ing
15:36 装唐
15:37 CCF与1939一个品性
15:44 大大们ACT2了
15:50 兴许ACT2
15:57 跑了56和87秒
16:04 不敢用SQFA
应该不会被卡吧 
16:16 旁边的ACT3了，在打游戏，强强
16:39 ccf肯定不卡SPFA
16:51 怎么都300了
17:13 大大们太强了
17:54 炸飞了 
不要慌，优势在我 
*/
