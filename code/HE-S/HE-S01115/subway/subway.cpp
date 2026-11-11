#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1],k[n+1];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int a[n+1][q+1],t[n+1][q+1];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int temp1,temp2;
			cin>>temp1>>temp2;
			a[i][j]=temp1;
			t[i][j]=temp2;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=k[i];j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//		for(int j=1;j<=k[i];j++){
//			cout<<t[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		cout<<ans+3*t[1][k[1]];
	}
	return 0;
}
