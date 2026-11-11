//GZ-S00126 贵阳市第一中学 谢云龙 
#include<bits/stdc++.h>
using namespace std;
const int N=18;
int head[N],to[2*N],nxt[2*N],cnt,is[N];
bool vis[N];
void add(int x,int y){
	nxt[++cnt]=head[x];
	to[cnt]=y;
	head[x]=cnt;
}
void dfs1(int x,int fa){

	vis[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(y!=fa&&is[y]==1){
			dfs1(y,x);
		}
	}
}
int dfs2(int x,int fa){
	int dep=12444;
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(y!=fa){
			if(is[y]){
				dep=1;
				return 1;
			}	
			else dep=min(dep,dfs2(y,x)+1);		
		}
	}
	if(dep==12444)return 0;
	return dep;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		fill(head,head+N,0);
		fill(to,to+N*2,0);
		fill(nxt,nxt+N*2,0);
		fill(is,is+N,0);
		int n,k,x,y,ans=0x3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		for(int m=0;m<=(1<<n);m++){
			int ma=m,cnt2=0;;
			fill(is,is+N,0);
			fill(vis,vis+N,0);
			for(int k=n-1;k>=0;k--){
			
				if(ma>=(1<<k)){
					is[k+1]=1;
					ma-=(1<<k);
					cnt2++;
				}
			}
			if(cnt2>k)continue;
			int cnt1=0;
			for(int i=1;i<=n;i++){
				if(is[i]&&vis[i]==0){
					dfs1(i,0);
					cnt1++;
				}
			}
			if(cnt1>2)continue;
			int mx=0;
			for(int i=1;i<=n;i++){
				if(is[i]==0){
					mx=max(mx,dfs2(i,0));
				}
			}
		//	cout<<mx<<" ";
			ans=min(ans,mx);
		}
		cnt=0;
		cout<<ans<<"\n";
	}
	return 0;
}
/*
oiiaioiiaioiiaioiiaioiiaioiiaioiiaioiiaioiiaioiiaioiiaioiiaioiiaioiiaioiiai     oi

*/
