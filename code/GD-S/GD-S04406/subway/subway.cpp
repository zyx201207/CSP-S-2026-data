#include<bits/stdc++.h>
using namespace std;
long long ans,c,n,m,d,q,w[125005],s[1005][1005],x,y,k[1005],a[1005][1005],t[1005][1005],temp;
//inline void Floyd(long long s,long long e){
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			for(int k=0;k<n;k++){
//				s[i][j]=min(s[i][k]+s[k][j],s[i][j]);
//			}
//		}
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			s[i][j]=t[i][i]+t[i][j]+t[j][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=w[x]+w[y];
	//	Floyd(x[i],y[i]);
		cout<<ans+t[x][y]+t[x][x]+t[y][y]<<"\n";
	}
	return 0;
}
