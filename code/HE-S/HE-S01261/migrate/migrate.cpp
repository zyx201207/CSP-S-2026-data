#include<bits/stdc++.h>
using namespace std;
const int maxn=4e6;
int c,t,n,d,x[maxn],timi[maxn],tot[5009][5009],ans;
int fir[maxn],nxt[maxn],to[maxn],val[maxn],tt;
void add(int x,int y,int z){
	nxt[++tt]=fir[x];fir[x]=tt;to[tt]=y;val[tt]=z;
}
struct node{
	int x,t;
	bool operator<(const node a)const{
		return a.t<t;
	}
};
void bfs(int s){
	priority_queue<node>q;
	memset(timi,-1,sizeof(timi));
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().x,ti=q.top().t;q.pop();
		if(timi[u]!=-1&&timi[u]!=ti) continue;
		timi[u]=ti;
		tot[s][u]++;
		for(int i=fir[u];i;i=nxt[i]){
			int v=to[i];
			q.push({v,ti+val[i]});
		} 
	} 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int iii=1;iii<=t;iii++){
		memset(tot,0,sizeof(tot));
		memset(fir,0,sizeof(fir));
		tt=0;
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int flag=0,com=0;
		for(int i=2;i<n;i++) if(x[i]-x[i-1]!=x[i+1]-x[i]) flag=1;
		if(flag==0){
			int dx=x[2]-x[1];
			if(d<2*dx){
				cout<<0<<endl;com=1;
			}else if(d<3*dx){
				if(n>=4) cout<<n-3<<endl;
				else cout<<0<<endl;
				com=1;
			}else{
				cout<<0<<endl;
				com=1;
			}
		} 
		if(com==1) continue;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d) break;
				add(i,j,1);
			}
		}
		for(int i=1;i<n;i++)bfs(i);
		ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(tot[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
