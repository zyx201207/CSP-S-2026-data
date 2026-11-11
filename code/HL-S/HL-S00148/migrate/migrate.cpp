#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[100010],ans,t,c,g[5010][5010],st[5050][5050],anss,anse,ti[2000020];
bool f=true;
int dfs(int u,int v,int x,int ts){
	if(x==v){
		if(ts==st[u][v]){
			anse++;
		}
	}
	for(int i=x+1;i<=v;i++){
		if(g[x][i]==1){
			dfs(u,v,i,ts+1);
		}
	}
	return anse;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>t;
	while(t--){
		anss=0;
		int n,d;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		memset(g,0,sizeof(g));
		memset(st,0,sizeof(st));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i<n)
			if(a[i+1]-a[i]!=a[i]-a[i-1]){
				f=false;
			}
		}
			if(f==true&&n>20000){
				int ansst=0;
				for(int i=3;i<=n-1;i++){
					int s=a[i+1]-a[1];
					if(s<2*d&&s>d){
						if(n-s==2){
							ansst++;
						}
					}
				}
			cout<<ansst<<"\n";
		}
		else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					g[i][j]=1;
					g[j][i]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int u=i,v=j,ans=0;
				while(u!=v){
				for(int k=u+1;k<=j;k++){
					if(g[u][k]==0){
						if(k==u+1){
							st[i][j]=-1;
							u=v;
							break;
						}
						u=k-1;
						ans++;
						continue; 
					}
					if(k==j){
						st[i][j]=ans+1;
						u=v;
						
					}
				}
			}
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				anse=0;
				if(dfs(i,j,i,0)==2){
					anss++;
				}
			}
		}
		cout<<anss<<"\n";
	}
}
	return 0;
}
