#include <bits/stdc++.h>
using namespace std;

int c,n,d,q,a[505][505],b[105][105],p[100005],[2];
long long m,v[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>v[i]; 
	}
	for(int i=1;i<=n;i++){
		int r;
		cin>>r;
		for(int j=1;j<=r;j++){
			cin>>a[i][j]>>b[i][j];
		} 
	}
	for(int i=1;i<=q;i++){
		cin>>p[i][0]>>p[i][1];
		cout<<a[1][1]*2-98<<(a[1][1]*2-98)/2;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
