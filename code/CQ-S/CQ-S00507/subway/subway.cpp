#include<bits/stdc++.h>
using namespace std;
long long e[1000009],dis[509][509];
vector<pair<long long,long long> >ve[1000009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	long long a,b,c,d;
	cin>>a;
	cin>>a>>b>>c>>d;
	for(long long i=1;i<=b;i++)cin>>e[i];
	for(long long i=1,x,y,z;i<=a;i++){
		cin>>x;
		while(x--){
			cin>>y>>z;
			ve[y].push_back({i,z});
		}
	}
	for(long long i=1;i<=a;i++)for(int j=1;j<=a;j++)dis[i][j]=1e18;
	for(int i=1;i<=a;i++)dis[i][i]=0;
	for(long long i=1;i<=b;i++){
		for(auto j:ve[i]){
			for(auto k:ve[i]){
				if(j.first==k.first)continue;
				dis[k.first][j.first]=dis[j.first][k.first]=min(dis[j.first][k.first],j.second+k.second);
			}
		}
	}
	for(long long i=1;i<=a;i++){
		for(long long j=1;j<=a;j++){
			for(long long k=1;k<=a;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	for(long long i=1,x,y;i<=d;i++){
		cin>>x>>y;
		long long ans=1e18;
		for(auto j:ve[x]){
			for(auto k:ve[y]){
				ans=min(ans,dis[j.first][k.first]+j.second+k.second);
			}
		}
		cout<<ans+e[x]+e[y]<<endl;
	}
	return 0;
}
