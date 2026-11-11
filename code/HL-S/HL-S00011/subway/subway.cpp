#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,a,t,dis[2005],z[2005][2005],x,y,cnt[2005];
int b[2005][25];
void di(int x){
	int q[2005],l=1,r=0;
	memset(dis,0x3f,sizeof(dis));
	dis[x]=0;
	q[++r]=x;
	while(l<m+n+1){
		for(int i=1;i<=cnt[q[l]];i++){
			if(dis[q[l]]+z[q[l]][b[q[l]][i]]<dis[b[q[l]][i]]){
				dis[b[q[l]][i]]=dis[q[l]]+z[q[l]][b[q[l]][i]];
				q[++r]=b[q[l]][i];
				
			}
		}
		l++;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a>>t;
			b[i+1000][++cnt[i+1000]]=a;
			b[a][++cnt[a]]=i+1000;
			z[i+1000][a]=t;
			z[a][i+1000]=t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		di(x);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}