#include<bits/stdc++.h>
using namespace std;
int w[500005];
vector<int> b[500005],t[500005];
long long dis[505][505];
int k[505];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int tmp1,tmp2;
			cin>>tmp1>>tmp2;
			b[tmp1].push_back(i);
			t[tmp1].push_back(tmp2);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=LONG_LONG_MAX;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<b[i].size();j++){
			for(int u=j+1;u<b[i].size();u++){
				dis[b[i][j]][b[i][u]]=dis[b[i][u]][b[i][j]]=min(dis[b[i][j]][b[i][u]],(long long)(t[i][j]+t[i][u]));
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]!=LONG_LONG_MAX&&dis[k][j]!=LONG_LONG_MAX) dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int tmp,tmp2;
		cin>>tmp>>tmp2;
		long long ans=LONG_LONG_MAX;
		for(int i=0;i<b[tmp].size();i++){
			for(int j=0;j<b[tmp2].size();j++){
				ans=min(ans,t[tmp][i]+dis[b[tmp][i]][b[tmp2][j]]+t[tmp2][j]); 
			}
		}
		cout<<ans+w[tmp]+w[tmp2]<<"\n";
	}
	return 0;
} 
