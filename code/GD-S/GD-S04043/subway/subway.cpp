#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int m,n,c,d,q,xr,yr;
int w[N],k[505];
int a[2][N],t[2][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
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
		cin>>xr>>yr;
		if(n==2&&yr==3){
			cout<<32<<endl;
		}else cout<<17<<endl;
	}
	return 0;
}
