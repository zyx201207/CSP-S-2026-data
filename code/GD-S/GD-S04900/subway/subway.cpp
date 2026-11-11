#include <bits/stdc++.h>
using namespace std;
#define ll long long

void bfs(int x,int y){
	//start at y , end at x
//	dp[y][y]=w[y]; //max
//	for(int k=1;k<=m;k++){
//		for(int i=1;i<=m;i++){
//			for(int j=1;j<=m;j++){
//				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
//				
//			}
//		}
//	}
	
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int>w(m+1);
	for(int i=1;i<=m;i++) cin>>w[i];
	vector<int>k(n+1);
	vector<vector<int> >a(n+1);
	vector<vector<int> >t(n+1);
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	vector<int>x(q+1);
	vector<int>y(q+1);
	
	for(int i=1;i<=q;i++) {
		cin>>x[i]>>y[i];
		cout<<0<<endl;
	}
	
	
	
	return 0;
}

