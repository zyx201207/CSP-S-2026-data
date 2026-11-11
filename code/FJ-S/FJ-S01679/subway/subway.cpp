#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[500010];
long long t[500010];
long long w[500010];
long long dis[1010][1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)
			dis[i][j]=2LL*1000000000*500010;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[j]>>t[j];
			for(int k=1;k<=j-1;k++){
				dis[a[j]][a[k]]=t[j]+t[k];
				dis[a[k]][a[j]]=t[j]+t[k];
			}
		}
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int st,ed;
		cin>>st>>ed;
		cout<<w[st]+dis[st][ed]+w[ed]<<endl;
	}
	return 0;
}
