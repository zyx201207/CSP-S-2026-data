#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
const int minn=4e4+5;
int read(){
	int t;
	scanf("%d",&t);
	return t;
} 
int c,t;
int n,k;
vector<int> e[maxn];
int f[minn][minn];
void dfs(int u,int fa,int a){
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==fa) continue;
		if(c<=10){
			if(f[a][v]>f[a][u]+1){
				f[a][v]=f[a][u]+1;
			}
		}
		dfs(v,u,a);
	}
}
int find(int u,int fa,int k){
	if(u==k) return k;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==fa) return 0;
		if(find(v,u,k)!=0){
			return v;
		} 
	}
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		memset(e,0,sizeof(e));
		for(int i=1;i<n;i++){
			int u,v;
			u=read(),v=read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=n;i++){
			f[i][i]=0;
			dfs(i,0,i);
		}
		int minn=n*n,pos=0;
		int p2=0;
		for(int i=1;i<=n;i++){
			int num=f[i][1];
			for(int j=2;j<=n;j++){
				num=max(num,f[i][j]);
			}
			if(minn>num){
				minn=num;
				pos=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(minn>f[pos][i]){
				minn=f[pos][i];
				p2=i;
			} 
		}
		for(int i=1;i<=n;i++){
			f[pos][i]=min(f[p2][i],f[pos][i]);
		}
		k-=2; 
		while(k--){
			for(int i=1;i<=n;i++){
				if(minn>f[pos][i]){
					minn=f[pos][i];
					p2=i;
				} 
			}
			p2=find(pos,0,p2);
			for(int i=1;i<=n;i++){
				f[pos][i]=min(f[p2][i],f[pos][i]);
			}
		}
		for(int i=1;i<=n;i++){
			if(minn>f[pos][i]){
				minn=f[pos][i];
			} 
		}
		cout<<minn<<endl;
	}
	return 0;
}
