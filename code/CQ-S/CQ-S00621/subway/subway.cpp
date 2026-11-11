#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
using namespace std;
const int N=510,M=5e5+10,inf=1e18;
int c,n,m,d,q;
int w[M],dis[N][N];
vector<pair<int,int> >a[N];
vector<pair<int,int> >belong[M];
//int val(int x,int i){
//	return a[i][lower_bound(a[i].begin(),a[i].end(),pair<int,int>{x,0})-a[i].begin()].second;
//}
int calc(int x,int i,int j,int y,int v1,int v2){
	return w[x]+v1+dis[i][j]+v2+w[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int k,i=1;i<=n;i++){
		cin>>k;
		for(int x,y,j=1;j<=k;j++)cin>>x>>y,a[i].push_back({x,y}),belong[x].push_back({i,y});
		sort(all(a[i]));
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=(i==j?0:inf);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			int l=0,r=0;
			while(l<a[i].size()&&r<a[j].size()){
				if(a[i][l].first<a[j][r].first)++l;
				else if(a[i][l].first>a[j][r].first)++r;
				else dis[i][j]=min(dis[i][j],a[i][l].second+a[j][r].second),++l,++r;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	for(int x,y,Q=1;Q<=q;Q++){
		cin>>x>>y;int tmp=inf;
		for(auto [i,v1]:belong[x]){
			for(auto [j,v2]:belong[y])tmp=min(tmp,calc(x,i,j,y,v1,v2));
		}
		cout<<tmp<<"\n";
	}
	return 0;
}
