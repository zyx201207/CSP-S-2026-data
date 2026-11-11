#include<bits/stdc++.h>
using namespace std;
const int maxm=5e5+5,maxn=505;
long long c,n,m,d,qq,ww[maxm],k[maxm],ed[maxn][maxn];
vector<long long> a[maxm],t[maxm];
int main(){
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)cin>>ww[i];
	fill_n(ed[0],maxn*maxn,1e15);
	for(int i=1;i<=n;i++){
		ed[i][i]=0;
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int v,w;
			cin>>v>>w;
			a[v].emplace_back(i);
			t[v].emplace_back(w);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j1=0;j1<a[i].size()-1;j1++){
			for(int j2=j1+1;j2<a[i].size();j2++){
				if(t[i][j1]+t[i][j2]<ed[a[i][j1]][a[i][j2]]){
					ed[a[i][j1]][a[i][j2]]=ed[a[i][j2]][a[i][j1]]=t[i][j1]+t[i][j2];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j1=1;j1<=n;j1++)for(int j2=1;j2<=n;j2++){
			ed[j1][j2]=min(ed[j1][j2],ed[j1][i]+ed[i][j2]);
		}
	}
	while(qq--){
		int x,y;
		cin>>x>>y;
		long long ans=1e15;
		for(int j1=0;j1<a[x].size();j1++){
			for(int j2=0;j2<a[y].size();j2++){
				ans=min(ans,ed[a[x][j1]][a[y][j2]]+t[x][j1]+t[y][j2]);
			}
		}
		cout<<ans+ww[x]+ww[y]<<'\n';
	}
	return 0;
} 
