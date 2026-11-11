#include<bits/stdc++.h>
using namespace std;
long long n,m,C,d,q,w[1000005],k,a,t,a1,t1,dis[1000][1000],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    memset(dis,0x3f3f3f3f,sizeof(dis));
    for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>a1>>t1;
		for(int j=1;j<k;j++){
			cin>>a>>t;
			dis[a][a1]=t1+t;
			dis[a1][a]=t1+t;
			a1=a,t1=t;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
}
