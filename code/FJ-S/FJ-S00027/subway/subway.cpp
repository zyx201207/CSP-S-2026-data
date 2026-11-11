#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long w[500005];
long long f[505][505]; 
long long a[505][500006];
vector<int>d[500005];
void get(){
	int c,D;
	memset(f,0x3f,sizeof(f));
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,x,y;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			a[i][x]=y;
			d[x].push_back(i);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	get();
	for(int i=1;i<=m;i++){
		if(d[i].size()==1)continue;
		for(int j:d[i]){
			for(int k:d[i]){
				if(j==k)f[j][k]=0;
				else f[j][k]=min(f[j][k],a[j][i]+a[k][i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long mi=0x3f3f3f3f;
		for(int i:d[x]){
			for(int j:d[y]){
				mi=min(f[i][j]+a[i][x]+a[j][y],mi);
			}
		}
		cout<<(w[x]+w[y]+mi)<<'\n';
	}
	return 0;
}
