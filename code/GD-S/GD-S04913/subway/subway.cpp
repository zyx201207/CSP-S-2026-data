#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,len,u,v;
long long a[500005];
long long ans[10005][10005];
struct node{
	long long x;
	long long y;	
}tmp[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)ans[i][j]=1e18;
	}
	for(int i=1;i<=n;i++){
		cin>>len;
		for(int j=1;j<=len;j++){
			cin>>tmp[j].x>>tmp[j].y ;
			for(int k=1;k<j;k++){
				if(ans[tmp[j].x ][tmp[k].x ]>tmp[j].y +tmp[k].y ){
					ans[tmp[j].x ][tmp[k].x ]=ans[tmp[k].x ][tmp[j].x ]=tmp[j].y +tmp[k].y;
					for(int ii=1;ii<=m;ii++){
						if(ans[tmp[j].x][ii]!=1e18 )ans[tmp[k].x][ii]=ans[ii][tmp[k].x ]=min(ans[tmp[k].x][ii],ans[tmp[j].x][ii]+ans[tmp[j].x ][tmp[k].x ]);
						if(ans[tmp[k].x][ii]!=1e18 )ans[tmp[j].x][ii]=ans[ii][tmp[j].x ]=min(ans[tmp[j].x][ii],ans[tmp[k].x][ii]+ans[tmp[j].x ][tmp[k].x ]);
					}
				}
			}
		}
	}	
	while(q--){
		cin>>u>>v;
		cout<<ans[u][v]+a[u]+a[v]<<endl;
	}
	return 0;
}
