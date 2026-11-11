#include<bits/stdc++.h>
using namespace std;
const int M=505,N=5e5+5,D=25;
#define ll long long
int n,m,d,q,hyw;
int a[N];
ll dis[M][M];
vector<pair<int,int> >sta[N];
void floyd(){
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>hyw>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		dis[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			sta[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<sta[i].size();j++)
		for(int k=0;k<sta[i].size();k++){
			int a=sta[i][j].first,c=sta[i][k].first;
			ll b=sta[i][j].second,d=sta[i][k].second;
			dis[a][c]=min(dis[a][c],b+d);
		}
	}
	floyd();
//	for(int i=1;i<=m;i++)for(int j=i+1;j<=m;j++)cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<sta[s].size();j++)
		for(int k=0;k<sta[t].size();k++){
			int a=sta[s][j].first,c=sta[t][k].first;
			ll b=sta[s][j].second,d=sta[t][k].second;
			ans=min(ans,b+d+dis[a][c]);
		}
		cout<<ans+a[s]+a[t]<<endl;
	}
}
//42	22	E:\FJ-S01067\subway\subway.cpp	[Warning] narrowing conversion of 'dis[v]' from 'long long int' to 'int' inside { } [-Wnarrowing]
