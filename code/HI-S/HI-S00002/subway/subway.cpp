#include<bits/stdc++.h>
using namespace std;
struct math{
	int id;
	long long val;
};
int c,n,m,d,q,k[505];
long long w[500005],dis[505][505];
vector<math>a[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x;
			long long y;
			cin>>x>>y;
			a[x].push_back(math{i,y});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) 
		   dis[i][j]=1000000000000000000;
	for(int p=1;p<=m;p++){
		for(int i=0;i<a[p].size();i++){
			for(int j=0;j<a[p].size();j++){
				int id_i=a[p][i].id,id_j=a[p][j].id;
				long long val_i=a[p][i].val,val_j=a[p][j].val;
				dis[id_i][id_j]=min(dis[id_i][id_j],val_i+val_j);
			}
		}
	}
	for(int p=1;p<=n;p++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
			}
		}
	}for(int i=1;i<=q;i++){
		int x,y;
		long long ans=1000000000000000000;
		cin>>x>>y;
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				int id_i=a[x][i].id,id_j=a[y][j].id;
				long long val_i=a[x][i].val,val_j=a[y][j].val;
				if(id_i==id_j) ans=min(ans,val_i+val_j);
				else ans=min(ans,dis[id_i][id_j]+val_i+val_j);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
