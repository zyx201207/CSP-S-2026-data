#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;

int a[N],f[N],vis[N];
int head[N],tot;
int nxt[N*2],to[N*2],w[N*2];

void add(int x,int y,int z){
	
	to[++tot]=y;
	w[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
	
}

void dijk(int s){
	
	queue<int> q;
	q.push(s); memset(f,0x3f,sizeof(f));
	
	f[s]=0;
	
	while (!q.empty()){
		
		int x=q.front(); q.pop();
		
		for (int i=head[x];i;i=nxt[i]){
			
			int y=to[i];
			
			if (f[x]+w[i]>f[y]) continue ;
			
			f[y]=f[x]+w[i]; q.push(y);
			
		}
		
	}
	
}

void dfs(int x){
	
	for (int i=head[x];i;i=nxt[i]){
		
		int y=to[i];
		
		if (vis[y]) continue ;
		vis[y]=1;
		
		cout<<x<<" "<<y<<" "<<w[i]<<"\n";
		dfs(y);
		
	}
	
	return ;
	
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;

	for (int i=1;i<=m;i++){
		
		cin>>a[i];
		
		for (int j=1;j<=n;j++){
			
			add(j,j+n,a[i]);
			add(j+n,j,a[i]);
			
			//for (int k=1;k<=)
			
		}
		
	}
	
	for (int i=1;i<=n;i++){
		
		int k,t=0; 
		cin>>k;
		
		for (int j=1;j<=k;j++){
			
			int x,y; cin>>x>>y;
			add(x+(j+2)*5,x,y);
			add(x,x+(j+2)*5,y);

			if (j==1) { t=x; continue ; }

			add(t,x,0); add(x,t,0); t=x;
			
		}
		
	}
	
	dfs(1);
	
	while (q--){
		
		int x,y;
		cin>>x>>y;
		
		dijk(x);
		
		cout<<f[y]+a[x]+a[y]<<"\n";
		
	}
	
	return 0;
	
}
