#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int w[500050];
	int a[1050][1050];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a1,t;
			cin>>a1>>t;
			a[i][a1]=t;
		}
	}
	
	
	return 0;
}
