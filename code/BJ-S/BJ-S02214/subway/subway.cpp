#include<bits/stdc++.h>
using namespace std;
struct N{
	int t,z;
}xian[505][500005];
int zhan[500005],a[500005],ans,vis[500005];
    int c,n,m,d,q;
void jt(int start,int end,int time,int k){
	if(start==end){
		for(int j=1;j<=xian[j][0].z;j++){
				if(xian[k][j].z==end){
					end=j;
				}
			}
		ans=min(time+xian[k][end].t,ans);
		return;
	}
	for(int i=1;i<=xian[k][0].z;i++){
		if(zhan[xian[k][i].z]==1||vis[xian[k][i].z]==1)continue;
		vis[xian[k][i].z]=1;
		jt(xian[k][i].z,end,time,k);
		vis[xian[k][i].z]=0;
	}
	for(int j=1;j<=n;j++){
			for(int i=1;i<=xian[j][0].z;i++){
				if(xian[j][i].z==start){
					jt(start,end,time+xian[k][start].t+xian[j][i].t,i);
				}
			}
		}
	return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("sabway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
		cin>>xian[i][0].z;
		for(int j=1;j<=xian[i][0].z;j++){
			cin>>xian[i][j].z>>xian[i][j].t;
			zhan[xian[i][j].z]++;
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		
		for(int j=1;j<=n;j++){
			for(int k=1;k<=xian[j][0].z;k++){
				if(xian[j][k].z=s){
					ans=1e9;
					vis[s]=1;		
					jt(s,e,a[s]+a[e],n);
					vis[s]=0;
					cout<<ans<<endl;
				}
			}
		}
	}
    return 0;
}
