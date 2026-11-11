#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[500005],x,y,aa[505][505],t,l,r,minn=0x3f3f3f3f3f3f3f3f,ans;
vector<long long> g[500005],f[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(long long i=1;i<=m;i++){
    	scanf("%lld",&a[i]);
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i==j) aa[i][j]=0;
			else aa[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
    for(long long i=1;i<=n;i++){
    	scanf("%lld",&y);
    	for(long long j=1;j<=y;j++){
    		scanf("%lld%lld",&x,&t);	
    		g[x].push_back(i);
    		f[x].push_back(t); 
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=0;j<g[i].size()-1;j++){
			for(long long k=j+1;k<g[i].size();k++){
				long long xx=g[i][j],yy=g[i][k];
				aa[xx][yy]=min(aa[xx][yy],f[i][j]+f[i][k]);
				aa[yy][xx]=min(aa[yy][xx],f[i][j]+f[i][k]);
			} 
		} 
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i==j) continue;
			for(long long k=1;k<=n;k++){
				if(i==k||j==k) continue;
				aa[i][j]=min(aa[i][j],aa[i][k]+aa[k][j]);
			}
		}
	}
	for(long long i=1;i<=q;i++){
		scanf("%lld%lld",&l,&r);
		minn=0x3f3f3f3f3f3f3f3f;
		for(long long j=0;j<g[l].size();j++){
			for(long long k=0;k<g[r].size();k++){
				long long xx=g[l][j],yy=g[r][k];
				ans=aa[xx][yy]+a[l]+f[l][j]+f[r][k]+a[r];
				minn=min(minn,ans);
			}
		}
		printf("%lld\n",minn);
	} 
	return 0;
}
