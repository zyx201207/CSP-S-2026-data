//GZ-S00158 贵阳市第三中学 李书涵
#include<bits/stdc++.h>
using namespace std;
const int N=510;
int c,n,m,d,q,x,y;//地铁线路数、地铁站数、最多被几条线路经过.出行计划数
int w[N],k[N],vis[N];//从每个地铁站的地铁口走到站厅需要的时间 线路经过的地铁站数
struct node{
	//a经过的第 j 个地铁站，t 表示从该地铁站的站厅走到站台需要的时间。
	int a[N],t[N];	
};
node lx[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>lx[i].a[j]>>lx[i].t[j];
		}
	}
	long long ans=0;
	while(q--){
		cin>>x>>y;
		ans+=w[x];
		
		for(int i=x;i<=y;i++){
			
			for(int j=1;j<=n;j++){
				for(int l=1;l<=k[j];l++){
					if(lx[j].a[l]==i){
						ans+=lx[j].t[l];		
						break;
					}
				}
			}		
		}
		cout<<ans+w[y]<<endl;
		ans=0;
	}
	
	return 0;
}
