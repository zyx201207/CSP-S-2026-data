#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,st,ed,now;
int q1,q2;
long long ans;
int f[2005][2005];
int r676767[500005];
int vis[2005];bool ok[2005];
void dij(int ler){
	vis[ler]=0;
	int mj=now-1;
	while(mj--){
		int r=0x3f3f3f3f+1,t=-91;
		for(int i=1;i<now;i++){
			if(vis[i]<r&&!ok[i]){
				r=vis[i];
				t=i;
			}
		}
		if(t==-91) break;
		ok[t]=1;
		for(int i=1;i<now;i++){
			if(f[t][i]!=-1&&!ok[i]){
				vis[i]=min(vis[i],vis[t]+f[t][i]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>r676767[i];
	memset(f,-1,sizeof f);
	now=m+1;
	for(int i=1;i<=n;i++){
		cin>>c;
		int ll=now,rr=c;
		for(int j=1;j<=c;j++){
			cin>>q1>>q2;
			f[now][q1]=f[q1][now]=q2;
			now++; 
		}
		for(int i=ll;i<ll+c-1;i++)
			f[i][i+1]=f[i+1][i]=0;
	}
	
	while(q--){
		cin>>st>>ed;
		memset(ok,0,sizeof ok);
		memset(vis,0x3f3f3f3f,sizeof vis);
		ans=r676767[st]+r676767[ed];
		dij(st);
		cout<<ans+vis[ed]<<'\n';
	}
	return 0;
}
