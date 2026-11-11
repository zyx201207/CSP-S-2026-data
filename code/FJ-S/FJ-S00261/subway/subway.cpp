#include<bits/stdc++.h>
using namespace std;
const int maxp=5*1e5+10;int lt=-1;bool fa,fb=1;
int c,n,m,d,q;long long dis[maxp];
bool vis[maxp];
struct ed{
	int from;int to;int weigh; 
};
vector<ed> e[maxp];
int zt[maxp];vector<int> way[509],zti[maxp];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>zt[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;if(lt==-1) lt=t;
			else if(lt!=t){
				fb=0;
			}
			way[i].push_back(a);
			zti[a].resize(d+1);
			zti[a][i]=t;
		}
		
		for(int j=0;j<k;j++){
			for(int l=j+1;l<k;l++){
				e[way[i][j]].push_back({way[i][j],way[i][l],zti[way[i][j]][i]+zti[way[i][l]][i]});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int i=0;i<=maxp;i++){
			dis[i]=1e18;
			vis[i]=0;
		}
		int now=x;
		dis[x]=0;vis[x]=1;
		while(1){
			if(vis[y]==1)
			{
				break;
			}
			for(int i=0;i<e[now].size();i++){
				dis[e[now][i].to]=min(dis[e[now][i].to],dis[now]+e[now][i].weigh);
			}
			long long minn=1e18,minl=0;
			for(int i=1;i<=m;i++){
				if(dis[i]<minn&&vis[i]==0){
					minn=dis[i];
					minl=i;
				}
			}
			now=minl;
			vis[minl]=1;
		}
		cout<<zt[x]+zt[y]+dis[y]<<endl;
	}
	return 0;
}
