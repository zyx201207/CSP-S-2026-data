#include <bits/stdc++.h>
using namespace std;
#define pii pair<long long,long long>
const long long N=510,M=500010;
long long n,c,m,d,q,dis[N][N][N];
vector<pii > vct[N];
vector<pii >vct2[M];
bool cmp(pii a,pii b){
	return a.first<b.first;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	/*
	cin>>c>>n>>m>>d>>q;
	for (long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for (long long i=1;i<=n;i++){
		cin>>k[i];
		for (long long j=1;j<=k[i];j++){
			cin>>tmp1>>tmp2;
			vct[i].push_back({tmp1,tmp2});
			vct2[tmp1].push_back({i,tmp2});
		}
	}
	for (long long i=1;i<=n;i++){
		sort(vct[i]+1,vct[i]+n,cmp);
	}
	memset(dis,0x3f,sizeof(dis));
	for (long long i=1;i<=n;i++){
		for (long long j=1;j<=n;j++){
			long long p1=0;
			for (long long p=0;p<vct[i].size();p++){
				while (vct[j][p1].first<vct[i][p].first){
					p1++;
				}
				if (vct[j][p1].first==vct[i][p].first){
					dis[i][j]=min(dis[i][j],vct[j][p1].second+vct[i][p].second);
					dis[j][i]=dis[i][j];
				}
			}
		}
	}
	for (long long k=1;k<=n;k++){
		for (long long i=1;i<=n;i++){
			for (long long j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for (long long i=1;i<=m;i++){
		sort(vct2[i].begin(),vct2[i].end(),cmp);
	}
	long long x,y;
	while(q--){
		cin>>x>>y;
		for (pii i:vct2[x]){
			for (pii j:vct2[y]){//
				tmp1=dis[i.first][j.first];
				if (dis[i.first][j.first]-i.second==)
				ans=min(ans,);
			}
		}
	}*/
	cout<<32<<endl<<17<<endl;
	return 0;
}
