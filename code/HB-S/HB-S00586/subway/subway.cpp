#include<bits/stdc++.h>
using namespace std;
long long C,n,m,d,q,w[500010],a[500010],t[500010];
long long f[1010][1010];
vector<pair<int,int> >g[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			f[i][j]=214748364;
			f[i][i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int x=1;x<j;x++){
				f[a[x]][a[j]]=min(f[a[x]][a[j]],t[x]+t[j]);
				f[a[j]][a[x]]=f[a[x]][a[j]];
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(f[i][k]<214748364&&f[k][j]<214748364){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long cnt=w[x]+w[y]+f[x][y];
		cout<<cnt<<'\n';
	}
	return 0;
}
