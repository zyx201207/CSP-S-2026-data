#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[N],a[510][N],t[510][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cout<<a[i][j]<<t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0;
		}
	}
	return 0;
} 
