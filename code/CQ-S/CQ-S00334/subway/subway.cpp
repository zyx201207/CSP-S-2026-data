#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,W[600],K,l,r,u,v,x,ans,zzb;
long long f[600][600];
vector<long long>w[600650];
vector<long long>p[600650];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>W[i];
	for(int i=1;i<=n;i++){
		cin>>K;
		for(long long j=1;j<=K;j++){
			cin>>u>>x;zzb=510000+i;
			w[zzb].push_back(x);
			w[u].push_back(x);
			p[u].push_back(zzb);
			p[zzb].push_back(u);		
		}
	}
	memset(f,0x3f,sizeof(f));
	
	for(long long i=1;i<=n;i++){//i->地铁 
		for(long long j=0;j<p[510000+i].size();j++){//j->地铁的第几个站 
			l=p[510000+i][j];//l->地铁站 
			for(long long k=0;k<p[l].size();k++){//j->能到站的第几个地铁
				r=p[l][k]-510000;//r->地铁 
				if(i==r)continue;
				f[i][r]=min(f[i][r],w[510000+i][j]+w[l][k]);
				f[r][i]=f[i][r];
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			for(long long k=1;k<=n;k++){
				f[i][k]=min(f[i][k],f[i][j]+f[j][k]);
				f[k][i]=f[i][k];
			}
		}
	}
	for(long long i=1;i<=n;i++)f[i][i]=0;
	for(long long i=1;i<=q;i++){
		cin>>u>>v;
		ans=LONG_LONG_MAX;
		for(long long j=0;j<p[u].size();j++){
			for(long long k=0;k<p[v].size();k++){
				ans=min(ans,f[p[u][j]-510000][p[v][k]-510000]+w[u][j]+w[v][k]);
			}
		}cout<<ans+W[u]+W[v]<<endl;
	}
	return 0;
}/*
地铁节点510000+i 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
125100000
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
