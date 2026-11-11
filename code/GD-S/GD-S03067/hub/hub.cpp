#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,k,dis[1005][1005],th[1005][1005];

void sv(){
	ll mi=0x3f3f3f3f;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				dis[i][j]=0;
				th[i][j]=1;
			}
			else{
				dis[i][j]=0x3f3f3f3f;
				th[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n-1;i++){
		ll u,v;
		dis[u][v]=1;
		dis[v][u]=1;
		th[u][v]=1;
		th[v][u]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	ll a[505];
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	do{
		ll f=0,mx=0;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=k;j++){
				if(i==j) continue;
				//cout<<a[i]<<' '<<a[j]<<endl;
				if(th[a[i]][a[j]]){f=1;break;}
				mx=max(dis[a[i]][a[j]],mx);
			}
			if(f) break;
		}
		if(f) continue;
		mi=min(mi,mx);
	}while(next_permutation(a+1,a+n+1));
	cout<<mi<<endl;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sv();
	}
	return 0;
}
