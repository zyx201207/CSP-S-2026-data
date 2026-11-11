#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long ent[500005],dis[505][505];
struct tp{
	int blg[22],len=0;
	long long t[22];
}pt[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&ent[i]);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		int l;
		long long r;
		for(int j=1;j<=k;j++){
			scanf("%d%lld",&l,&r);
			for(int p=1;p<=pt[l].len;p++)dis[pt[l].blg[p]][i]=dis[i][pt[l].blg[p]]=min(dis[pt[l].blg[p]][i],pt[l].t[p]+r);
			pt[l].len++;
			pt[l].blg[pt[l].len]=i;
			pt[l].t[pt[l].len]=r;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j])dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
			}
		}
	}
	long long ans;
	for(int i=1,st,ed;i<=q;i++){
		scanf("%d%d",&st,&ed);
		ans=4557430888798830399;
		for(int l=1;l<=pt[st].len;l++){
			for(int r=1;r<=pt[ed].len;r++)ans=min(ans,pt[st].t[l]+pt[ed].t[r]+dis[pt[st].blg[l]][pt[ed].blg[r]]);
		}
		ans=ans+ent[st]+ent[ed];
		printf("%lld\n",ans);
	}
	return 0;
}
