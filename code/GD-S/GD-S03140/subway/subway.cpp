#include<bits/stdc++.h>
using namespace std;
int k[505],a[501][500005],t[501][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int>w(m+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				ans+=t[i][j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
