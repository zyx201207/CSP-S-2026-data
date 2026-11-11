#include<bits/stdc++.h>
using namespace std;
long long n,m,c,d,q,k,aa,tt;
struct node{
	long long v,id;
};
struct nodee{
	long long cost,belong;
};
long long dis[505][505];
vector<nodee>point[500005];
long long w[500005];
vector<int>belongg[500005];
map<int,int>mp[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=998244353535;
		}dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&aa,&tt);
			mp[i][aa]=tt;
			belongg[aa].push_back(i);
			
			for(int kk=0;kk<point[aa].size();kk++){
				dis[point[aa][kk].belong][i]=min(dis[point[aa][kk].belong][i],tt+point[aa][kk].cost);
				dis[i][point[aa][kk].belong]=min(dis[i][point[aa][kk].belong],tt+point[aa][kk].cost);
			}
			point[aa].push_back({tt,i});
		}
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	//cout<<dis[1][2]<<" *\n";
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		long long minn=99824435353535353;
		long long bestx=-1,besty=-1;
		for(int l=0;l<belongg[x].size();l++){
			for(int r=0;r<belongg[y].size();r++){
				if(minn>dis[belongg[x][l]][belongg[y][r]]){
					minn=min(minn,dis[belongg[x][l]][belongg[y][r]]);
					bestx=belongg[x][l];
					besty=belongg[y][r];
				}
				
			}
		}
		if(x==y){
			cout<<"0\n";
			continue;
		}
		//cout<<" "<<bestx<<" "<<besty<<"   ";
		cout<<minn+w[x]+w[y]+mp[bestx][x]+mp[besty][y]<<"\n";
	}
	return 0;
}
