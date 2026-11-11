#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
int c,n,T,kk,d[N],sz[N],ma,w[310][310],ans,ss,dep[N];
int e[N],ne[N],idx,h[N];
void add(int u,int v){
	e[idx]=v;
	ne[idx]=h[u];
	h[u]=idx++;
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	if(dep[u]>dep[ss]) ss=u;
	for(int i=h[u];i!=-1;i=ne[i]){
		int v=e[i];
		if(v==fa) continue;
		dfs(v,u);
	}
}
int pop_count(int x){
	int res=0;
	while(x){
		if(x&1) res++;
		x/=2;
	}
	return res;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	memset(h,-1,sizeof(h));
	cin>>c>>T;
	while(T--){
		idx=0;
		scanf("%d %d",&n,&kk);
		if(n<=310){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) w[i][j]=2*n;
				w[i][i]=0;
			}
		}
		for(int i=1;i<=n;i++) h[i]=-1;
		ans=0;
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			if(n<310) w[u][v]=w[v][u]=1;
			add(u,v);
			add(v,u);
		}
		if(n<310){
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++) w[i][j]=min(w[i][k]+w[k][j],w[i][j]);
				}
			}
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=n;j++) cout<<w[i][j]<<" ";
//				cout<<endl;
//			}
			int tmp1=0,tmp2=2*n;
			ans=2*n;
			for(int mask=1;mask<(1<<n);mask++){
				int x=pop_count(mask);
				if(x!=kk) continue;
				int ttp=0;
				for(int i=2;i<=n;i++){
					if((mask&(1<<(i-1)))&&!(mask&(1<<(i-2)))) ttp++;
				}
				if(ttp!=1) continue;
				tmp1=0;
//				cout<<mask<<" ";
				for(int i=1;i<=n;i++){
					tmp2=2*n;
					for(int j=1;j<=n;j++){
						if(mask&(1<<(j-1))) tmp2=min(tmp2,w[i][j]);
					}
					tmp1=max(tmp1,tmp2);
				}
//				cout<<tmp1<<endl;
				ans=min(ans,tmp1);
			}
			printf("%d\n",ans);
			continue;
		}
		dfs(1,0);
		dfs(ss,0);
		printf("%d\n",(dep[ss]-kk+kk)/((kk-1)*2+2));
//		if(k==1){
//			for(int i=1;i<=n;i++){
//				if(ma>abs(sz[i]-(n-sz[i]-1))){
//					ma=abs(sz[i]-(n-sz[i]-1));
//					ans=i;
//				}
//			}
//			printf("%d\n",i);
//		}
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
*/
