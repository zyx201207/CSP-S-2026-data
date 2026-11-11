#include<bits/stdc++.h>
using namespace std;
int c,n,m,dd,q,s,e,ans;
int w[500100];
//int se[1000][1000];
struct ss{
	int lineee,fy,ne;
}d[500100];
int a[500100],anw;
void fadd(int lin,int p,int f){
	anw++;
	d[anw].ne=a[p];
	a[p]=anw;
	d[anw].lineee=lin;
	d[anw].fy=f;
//	for(int i=a[p];i;i=d[i].ne){//二者连通的标志 
//		int nlin=d[i].lineee;
//		se[nlin][lin]=1;
//		se[lin][nlin]=1;
//	}
}
struct sss{
	int v,nene,linee;
}b[500100];
int h[500100],nw;
void add(int lp,int p,int lin){
	nw++;
	b[nw].nene=h[lp];
	h[lp]=nw;
	b[nw].linee=lin;
	b[nw].v=p;
}
int hx(int bd,int deli){
	for(int i=a[bd];i;i=d[i].ne){
		if(d[i].lineee==deli){
			return d[i].fy;
		}
	}
	return 0x3f3f3f3f;
}
int fyjs(int bd,int li,int deli){
	if(li==deli){
		return 0;
	}else if(li==0){
		return hx(bd,deli);
	}else{
		return hx(bd,li)+hx(bd,deli);
	}
}
int bj[500100];
void dfs(int li,int x,int f){
	if(x==e){
		ans=min(ans,f);
	}
	if(f>ans)return;
	for(int i=h[x];i;i=b[i].nene){
		int y=b[i].v;
		if(bj[y]==0){
			//计算费用
			f+=fyjs(x,li,b[i].linee);
			bj[y]=1;
			dfs(b[i].linee,y,f);
			bj[y]=0;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>dd>>q;
	if(c!=-1){//gaij 
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		int k;
		for(int i=1;i<=n;i++){
			cin>>k;
			int lp=0;
			for(int j=1;j<=k;j++){
				int p,t;
				cin>>p>>t;
				fadd(i,p,t);
				if(lp!=0){
					add(lp,p,i);
					add(p,lp,i);
				}
				lp=p;
			}
		}
	}
	while(q--){
		ans=0x3f3f3f3f;
		cin>>s>>e;
		dfs(0,s,w[s]+w[e]);
		cout<<ans<<endl;
	}
	return 0;
}
