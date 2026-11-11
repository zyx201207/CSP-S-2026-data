#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,xx,y;
int w[100005],a[505][100005],t,k,x[1005][1005];bool b[1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=1000;i++)for(int j=1;j<=1000;j++)x[i][j]=100000005;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	if(c>=7 and c<=11){
		for(int i=1;i<=m;i++){
			scanf("%d",&w[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&k);
			for(int j=1;j<=2;j++){
				scanf("%d%d",&a[i][j],&t);
			}
			x[a[i][1]][a[i][2]]=2*t;
			x[a[i][2]][a[i][1]]=2*t;
		}
		for(int i=1;i<=q;i++){
			scanf("%d%d",&xx,&y);
			int v[1005];
			for(int j=1;j<=1000;j++)v[j]=100000005;
			v[xx]=0;
			for(int j=1;j<=m;j++){
				int mi=0,minn=100000005;
				for(int e=1;e<=m;e++){
					if(b[e]==0 and minn>v[e]){
						mi=e;minn=v[e];
					}
				}
				b[mi]=1;
				if(mi==y)break;
				for(int e=1;e<=m;e++){
					if(b[e]==0)v[e]=min(v[e],v[mi]+x[mi][e]);
				}
			}
			cout<<w[xx]+w[y]+v[y]<<endl;
		}
	}
	return 0;
}
