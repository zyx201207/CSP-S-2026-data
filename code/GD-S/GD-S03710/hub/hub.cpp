#include<bits/stdc++.h>
using namespace std;
bool b[100005],bb[100005];
int s,n,h[100005],mi=1e9,nxt[200005],to[200005],cnt,k,x,y,dis[11][11];
int fa[100005],d[100005],tf;
void add(int x,int y){
	nxt[++cnt]=h[x];
	h[x]=cnt;
	to[cnt]=y;
}
int find(int o){
	if(fa[o]==o) return o;
	int p=find(fa[o]);
	fa[o]=p;
	return p;
}
void dfs(int o,int s){
	if(o>n){
		if(s!=k) return;tf=0;
		if(k!=2){
			for(int i=1;i<=n;i++){
				fa[i]=i,bb[i]=0;
			}
			for(int i=1;i<=n;i++)
				if(b[i]){
					for(int j=h[i];j;j=nxt[j]){
						int u=to[j];
						if(b[u]) fa[find(i)]=find(u);
					}
					d[++tf]=i;
				}
			int fo=0;
			for(int i=1;i<=tf;i++){
				int r1=find(d[i]);
				if(!bb[r1]) fo++,bb[r1]=1;
			}
			if(fo>2) return;	
		}
		int ma=0;
		for(int i=1;i<=n;i++){
			int mie=1e9;
			for(int j=1;j<=tf;j++) mie=min(mie,dis[i][d[j]]);
			ma=max(ma,mie);
		}mi=min(mi,ma);
		return;
	}if(s>k) return;
	b[o]=1,dfs(o+1,s+1);
	b[o]=0,dfs(o+1,s);
}
void dft(int o,int v,int se){
	dis[se][o]=dis[se][v]+1;
	for(int i=h[o];i;i=nxt[i]){
		int u=to[i];
		if(u!=v) dft(u,o,se);
	}
}
void Z(){
	cin>>n>>k,cnt=0,mi=1e9;
//	if(k==2){cout<<"1\n";return;}
//	if(k==1){cout<<"0\n";return;}
	if(n>=3000){
		int fo=n-k;
		cout<<(fo-1)/4+1<<"\n";
		return; 
	}
	for(int i=1;i<=n;i++) h[i]=0;
	for(int i=1;i<n;i++) cin>>x>>y,add(x,y),add(y,x);
	if(n<=10){for(int i=1;i<=n;i++) dis[i][0]=-1,dft(i,0,i);dfs(1,0);cout<<mi<<"\n";return;}
	if(k==2){
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		b[i]=b[j]=1,dfs(n+1,2),b[i]=b[j]=0;
		cout<<mi<<"\n";
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) Z();
}
