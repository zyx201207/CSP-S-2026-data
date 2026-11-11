#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,dis[505][505],w[500005];
map<int,long long> st[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int tmp1,tmp2;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>tmp1>>tmp2;
			st[tmp1][i]=tmp2;
		}
	}
	memset(dis,0x1f,sizeof(dis));
	for(int i=1;i<=m;i++){
		for(auto p:st[i]){
			for(auto q:st[i]){
			dis[q.first][p.first]=dis[p.first][q.first]=min(dis[p.first][q.first],p.second+q.second);
		}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	long long ans;
	while(q--){
		cin>>tmp1>>tmp2;
		ans=0x1f1f1f1f1f1f1f1f;
		for(auto i:st[tmp1]){
			for(auto j:st[tmp2]){
				ans=min(ans,w[tmp1]+w[tmp2]+i.second+j.second+dis[i.first][j.first]);
		}
		}
		cout<<ans<<"\n";
		
	}
	return 0;
} 
