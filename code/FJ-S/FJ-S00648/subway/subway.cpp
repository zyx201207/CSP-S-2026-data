#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,q,l,r,w,a[5005],p[5005][2],v[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>t>>n>>m>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			v[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(t--){
		cin>>w;
		for(int i=1;i<=w;i++){
			cin>>p[i][0]>>p[i][1];
			for(int j=1;j<i;j++){
				int I=p[i][0],J=p[j][0];
				v[I][J]=p[i][1]+p[j][1];
				v[J][I]=v[I][J];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(v[i][k]==1e18 || v[k][j]==1e18) continue;
				v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
				v[j][i]=v[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		cout<<v[l][r]+a[l]+a[r]<<endl;
	}
	return 0;
}
