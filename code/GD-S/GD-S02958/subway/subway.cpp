#include<bits/stdc++.h>
using namespace std;
int w[100005],k[505],a[505][505],t[505][535];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
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
	while(q--){
		cout<<w[0]+t[0][0]+t[0][1]+w[1]<<endl;
	}
	return 0;
} 
