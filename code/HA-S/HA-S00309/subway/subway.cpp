#include<bits/stdc++.h>
using namespace std;
const int N=600000;
int be[N],w[N],to[N],nxt[N*2],se=0,sn,ans=1e9,vis[N];
int wt[N],a[N],t[N],k[N];
int add(int x,int y,int z){
	se++;
	to[se]=y;
	nxt[se]=be[x];
	be[x]=se;
	w[se]=z;
}
void dfs(int u,int v,int t){
	if(u==v){
		ans=min(ans,t);
		return;
	}
	for(int i=be[u];i;i=nxt[i]){
		int k=to[i];
		if(vis[k]==0){
			vis[k]=1;
			dfs(k,v,t+w[i]);
			vis[k]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	sn=m*2;
	for(int i=1;i<=m;i++){
		cin>>wt[i];
		add(i,m+i,wt[i]);
		add(m+i,i,wt[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int c=sn;
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			sn++;
			add(a[j],sn,t[j]);
			add(sn,a[j],t[j]);
		}
		c++;
		for(int j=c;j<=sn;j++){
			for(int p=j+1;p<=sn;p++){
				add(c,p,0);
				add(p,c,0);
			}
		}
	}
	while(p--){
		int s1,s2;
		cin>>s1>>s2;
		for(int i=1;i<=sn;i++){
			vis[i]=0;
		}
		ans=1e9;
		dfs(s1,s2,0);
		cout<<ans+wt[s1]+wt[s2]<<endl;
	}
	return 0;
}