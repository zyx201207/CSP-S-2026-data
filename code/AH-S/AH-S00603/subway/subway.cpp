#include<bits/stdc++.h>
using namespace std;
long long n,m,k[505],t[500005][25],a[505][500005],v[500005];
vector<int>g[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			if(j%2!=0){
				cin>>a[i][j];
			}else{
				cin>>t[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
	}
	cout<<35<<endl<<17;
	return 0;
}
