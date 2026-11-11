#include<bits/stdc++.h>
using namespace std;
const int N=200;
#define ll long long
struct poi{
	int tto,nxt;
}en[10*N];
int tot,head[20*N];
int cl[N],dep[N];
void add(int u,int vv){
	++tot;
	en[tot].tto=vv;
	en[tot].nxt=head[u];
	head[u]=tot;
}
int vis[50];
void dfs2(int u,int fa){
	if(vis[u]==0)vis[u]=1;
	for(int i=head[u];i;i=en[i].nxt){
		int v=en[i].tto;
		if(cl[v]==1&&v!=fa){
			vis[v]=1;
			dfs2(v,u);
		}
	}
}
void dfs3(int u,int fa){
	for(int i=head[u];i;i=en[i].nxt){
		int v=en[i].tto;
		if(v!=fa){
			dep[v]=dep[u]+1;
			dfs3(v,u);
		}
	}
}
int ans=10000,n,k,c,t;
void rn(){
	int tmp=0;
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&cl[i]==1){
			vis[i]=1;
			tmp++;
			dfs2(i,0);
		}
	}
	if(tmp<=2){
	/*	cout<<"CHOICE:";
		for(int i=1;i<=n;i++){
			if(cl[i]==1){
		//		cout<<i<<" ";
			}
		}
		cout<<"\n";*/
		int	maxx=0;
		for(int i=1;i<=n;i++){
			dep[i]=0;
			dfs3(i,0);
			int minn=100000;
			for(int j=1;j<=n;j++){
				if(cl[j]==1){
					minn=min(minn,dep[j]);
		//			cout<<"MAMBA::::"<<dep[j]<<"\n";
				}
			}
			maxx=max(maxx,minn);
		}
		ans=min(ans,maxx);
	}
}
void sv(){
	memset(head,0,sizeof(head));
	memset(en,0,sizeof(en));
	ans=10000;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);add(y,x);
	}
	for(int i=0;i<(1<<n);i++){
		int	cnt=0;
		for(int j=1;j<=n;j++){
			cl[j]=0;
			if(i&(1<<(j-1))){
				cl[j]=1;cnt++;
			}
		}
		if(cnt==k){
//			cout<<"AAAAA::::::"<<"MEN::";
			rn();
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)sv();
}
