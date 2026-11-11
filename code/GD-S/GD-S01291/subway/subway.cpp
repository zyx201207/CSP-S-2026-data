#include<bits/stdc++.h>
using namespace std;
long long n,m,d,c,q,w[5005],dis[20005][20005];
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%ld",&w[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=3e9;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		long long k,a[20001],t[20002];
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a[j],&t[j]);
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				if(l!=j){
					dis[a[l]][a[j]]=min(t[l]+t[j],dis[a[l]][a[j]]);
					dis[a[j]][a[l]]=dis[a[l]][a[j]];
				}
			}
		} 
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
		    for(int j=1;j<=m;j++){
		    	if(i!=j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		    	dis[j][i]=dis[i][j];	
				}
		    }
	   }
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=0;
		ans=w[x]+w[y];
		cout<<ans+dis[x][y]<<endl;
	}
	return 0;
	
} 
