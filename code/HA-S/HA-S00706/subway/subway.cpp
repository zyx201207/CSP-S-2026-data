#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[1005],k,z,s,e,dis[1005][1005],a[1005][1005];
vector <long long> v[1005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=m;j++) {
			dis[i][j]=1e9;
		}
	}
	for (int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=m;j++) {
			dis[i][j]=1e9;
		}
	}
	for (int i=1;i<=n;i++) {
		cin>>k;
		for (int j=1;j<=k;j++) {
			cin>>z;
			cin>>a[i][z];
			v[i].push_back(z);
		}
		for (int j=0;j<v[i].size();j++) {
			for (int k=0;k<v[i].size();k++) {
				dis[v[i][j]][v[i][k]]=min(dis[v[i][j]][v[i][k]],w[v[i][j]]+a[i][v[i][j]]+a[i][v[i][k]]+w[v[i][k]]);
			}
		}
	}
	for (int k=1;k<=m;k++) {
		for (int i=1;i<=m;i++) {
			for (int j=1;j<=m;j++) {
				//cout<<i<<" "<<k<<" "<<j;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]-2*w[k]);
				//cout<<" "<<dis[i][j]<<endl;
				//cout<<"!!"<<dis[i][k]<<" "<<dis[k][j]<<" "<<w[k]<<"!!\n";
			}
		}
	}
	for (int i=1;i<=p;i++) {
		cin>>s>>e;
		cout<<dis[s][e]<<endl;
	}
	return 0;
}
