#include<bits/stdc++.h>

using namespace std;
int w[500005];
int k[501],a[501][501],t[501][501],x[26],y[26];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
			
		}
	}
	for(int i=0;i<c;i++){
		cin>>x[i]>>y[i];
	}
	
	for(int i=0;i<q;i++){
		int sum=w[x[i]]+w[y[i]];
		sum=sum+t[i][x[i]]+t[i][y[i]]+t[a[y[i]][i]][a[x[i]][i]]+t[i][c];
		cout<<sum<<endl;
	}
	
	
	return 0;
}












