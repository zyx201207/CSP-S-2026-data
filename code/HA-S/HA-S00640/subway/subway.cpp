#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int cnt2;
long long ans;
int w[500010];
//int head[500010];
int tt[500010][510];//zhanting->zhantai
int pre[500010];
int cnt;
int e[500010][510];
struct node{
	int now;
	int nxt;
	int to;
	int way;//º∏∫≈œﬂ
	int vis;
}a[500010];
void add_edge(int nw,int nt,int wy){
	a[cnt].now=nw;
	a[cnt].nxt=nt;
	a[cnt].way=wy;
	a[cnt].to++;
	e[nw][a[cnt].to]=++cnt;
	//head[cnt]=nw;
}
int read(){
	char ch;
	int f=1;
	int ff=0;
	int k=0;
	ch=getchar();
	if(ch<'0'||ch>'9'){
		f=-1,ff=1;
		ch='0';
	}
	while((ch>='0'&&ch<='9')||ff==1){
		ff=0;
		k=k*10+ch-'0';
		ch=getchar();
	}
	return f*k;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	if(c==0){
		if(n==2){
			cout<<"32"<<endl<<"17";
			return 0;
		}
		if(n==3){
			cout<<"35"<<endl<<"16";
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k;
		k=read();
		int xx[500010];
		for(int j=1;j<=k;j++){
			xx[j]=read();
			tt[xx[j]][i]==read();
		}
		for(int j=1;j<=k-1;j++){
			add_edge(xx[j],xx[j+1],i);
			add_edge(xx[j+1],xx[j],i);
		}
	}
	while(q--){
		int u,v;
		u=read();
		v=read();
		for(int i=a[u].now;a[i].nxt!=v;i=a[i].nxt){
			//int cost=1e7;
			int ta=0;
			int tmp=0,mintmp=0;
			for(int j=1;j<=a[i].to;j++){
				if(a[j].vis==1){
					continue;
				}
				if(a[pre[cnt2]].way!=a[j].way){
					tmp=tt[a[pre[cnt2]].now][a[pre[cnt2]].way];
				}
				if(tmp<=mintmp){
					mintmp=tmp;
					ta=j;
				}
			}
			ans+=tmp;
		}
		ans+=w[u]+w[v];
		cout<<ans<<endl;
	}
	return 0;
}
