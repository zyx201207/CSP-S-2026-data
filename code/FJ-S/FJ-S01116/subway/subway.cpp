#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
vector<long long> hc1[500001];
vector<long long> hc2[500001];
long long dis[501][501],n,c,m,d,q,l,l2,x,y,ans,k[501],edg[501][501],jz[500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(edg,63,sizeof(edg));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>jz[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>l>>l2;
			hc1[l].push_back(i);
			hc2[l].push_back(l2);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<hc1[i].size();j++){
			for(int k=j+1;k<hc1[i].size();k++){
				edg[hc1[i][j]][hc1[i][k]]=min(edg[hc1[i][j]][hc1[i][k]],hc2[i][j]+hc2[i][k]);
				edg[hc1[i][k]][hc1[i][j]]=edg[hc1[i][j]][hc1[i][k]];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				edg[i][j]=0;
			}
			dis[i][j]=edg[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<dis[i][j]<<' ';
			}
			cout<<endl;
		}		
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=8234567891234567890;
		for(int j=0;j<hc1[x].size();j++){
			for(int k=0;k<hc1[y].size();k++){
				ans=min(ans,hc2[x][j]+hc2[y][k]+dis[hc1[x][j]][hc1[y][k]]);
			}
		}
		cout<<ans+jz[x]+jz[y]<<endl;
	}
}
