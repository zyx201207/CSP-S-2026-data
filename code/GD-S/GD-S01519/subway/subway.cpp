#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,MA=1e9;
int c,n,m,d,q,w[N],k,a[22],t[22],f[N][N],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=MA;
	for(int i=1;i<=n;i++)cin>>w[i];
	while(m--){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
			for(int j=1;j<i;j++)f[a[i]][a[j]]=f[a[j]][a[i]]=t[i]+t[j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(j==i||j==k)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
