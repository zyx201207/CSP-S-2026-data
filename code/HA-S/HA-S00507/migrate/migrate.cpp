#include<bits/stdc++.h>
using namespace std;
int x[2000006],n,d;
int minn[2000006],sum[2000006];
int h[200005],nxt[200005],to[200005],cnt;
void add(int a,int b){
	to[++cnt]=b;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
void dfs(int x,int st){
	for(int i=h[x];i;i=nxt[i]){
		int v=to[i];
		if(v<x||minn[v]<st)continue;
		if(minn[v]==st)++sum[v];
		else{
			minn[v]=st;sum[v]=0;
			dfs(v,st+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>x[i];
		int f=1;
		for(int i=1;i<n-1;++i){
			if(x[i+1]-x[i]!=x[i+2]-x[i+1]){
				f=0;break;
			}
		}
		if(f==1){
			d/=(x[2]-x[1]);
			cout<<n-d+1<<endl;
		}
		else{
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(i!=j&&abs(x[i]-x[j])<=d)add(i,j);
				}
			}
			int ans=0;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j)minn[j]=1e9,sum[j]=0;
				dfs(i,1);
				for(int j=i;j<=n;++j)if(sum[j]==2)++ans;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
