#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;

int k,x,y,w[500001];
int a[500001],c1[500001],mp[1001][1001];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			mp[i][j]=1000000000;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>c1[j];
			for(int l=1;l<j;l++){
				mp[a[l]][a[j]]=mp[a[j]][a[l]]=c1[l]+c1[j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int l=1;l<=m;l++){
				mp[i][l]=min(mp[i][l],mp[i][j]+mp[j][l]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<mp[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
