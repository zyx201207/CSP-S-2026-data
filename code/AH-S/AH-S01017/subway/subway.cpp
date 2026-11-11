#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
/*
c:测试点编号
n:地铁线路数
m:地铁站数
d:每个地铁站最多被几条线路经过
q:出行计划数
*/
map <int,int> w;
int k[505];
map <int,map <int,int> > a;
map <int,map <int,int> > t;
int head[505];
map <int,int> nxt;
struct Edge{
	int v,w;
};
map <int,Edge> edge;
int p;
void add(int u,int v,int w){
	nxt[++p]=head[u];
	edge[p].v=v;
	edge[p].w=w;
	head[u]=p;
}
int ckkin(int x,int i){
	for(int j=1;j<=k[i];j++){
		if(a[i][j]==x){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n==1){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		int mn=0x7f7f7f7f;
		cin>>k[1];
		for(int j=1;j<=k[1];j++){
			cin>>a[1][j];
			int x=a[1][j];
			cin>>t[1][x];
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			long long ans=1ll*w[x]+1ll*w[y]+1ll*t[1][x]+1ll*t[1][y];
			cout<<ans<<"\n";
		}
		return 0;
	}
	if(n==2){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		long long mn=0x7f7f7f7f;
		cin>>k[1];
		for(int j=1;j<=k[1];j++){
			cin>>a[1][j];
			int x=a[1][j];
			cin>>t[1][x];
		}
		cin>>k[2];
		for(int j=1;j<=k[2];j++){
			cin>>a[2][j];
			int x=a[2][j];
			cin>>t[2][x];
			if(t[1][a[2][j]]){
				mn=min(mn,1ll*t[1][a[2][j]]+t[2][a[2][j]]);
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			long long ans=0x7f7f7f7f;
			int f11=ckkin(x,1);
			int f12=ckkin(x,2);
			int f21=ckkin(y,1);
			int f22=ckkin(y,2);
			if(f11){
				if(f21){
					ans=min(ans,1ll*t[1][x]+t[1][y]);
				}
				if(f22){
					ans=min(ans,mn+1ll*t[1][x]+t[2][y]);
				}
			}
			if(f12){
				if(f21){
					ans=min(ans,mn+t[2][x]+t[1][y]);
				}
				if(f22){
					ans=min(ans,1ll*t[2][x]+t[2][y]);
				}
			}
			cout<<ans+1ll*w[x]+1ll*w[y]<<"\n";
		}
		return 0;
	}
	if(n==3){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		cin>>k[1];
		for(int j=1;j<=k[1];j++){
			cin>>a[1][j];
			int x=a[1][j];
			cin>>t[1][x];
		}
		cin>>k[2];
		for(int j=1;j<=k[2];j++){
			cin>>a[2][j];
			int x=a[2][j];
			cin>>t[2][x];
			if(ckkin(x,1)){
				add(1,2,t[1][x]+t[2][x]);
			}
		}
		cin>>k[3];
		for(int j=1;j<=k[2];j++){
			cin>>a[3][j];
			int x=a[3][j];
			cin>>t[3][x];
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			long long ans=1ll*w[x]+1ll*w[y];
			int ck1=ckin(x);
			int ck2=ckin(y);
			if(ck1==ck2){
				ans+=t[ck1][x];
				ans+=t[ck1][y];
			} else {
				ans+=t[ck1][x];
				ans+=mn;
				ans+=t[ck2][y];
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
//	for(int i=1;i<=m;i++){
//		cin>>w[i];
//	}
//	for(int i=1;i<=n;i++){
//		cin>>k[i];
//		for(int j=1;j<=k[i];j++){
//			cin>>a[i][j]>>t[i][a[i][j]];
//		}
//	}
//	while(q--){
//		int x,y;
//		cin>>x>>y;
//		if(c==21||c==22){
//			
//		}
//	}
	return 0;
}

