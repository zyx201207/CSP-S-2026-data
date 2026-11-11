#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[505];
int a[5][505],t[5][505];
int k[505];int l,r;
vector<int> vec[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			vec[a[i][j]].push_back(i);
		}
	}
	while(q--){
		cin>>l>>r;
		cout<<r-l+1<<"\n";
	}
	return 0;
}
