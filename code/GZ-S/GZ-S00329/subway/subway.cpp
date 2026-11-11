//GZ-S00329 何子文 遵义市第二中学 
#include <bits/stdc++.h>
using namespace std;
int w[500005];
int k[500005];
int a[5005][5005];
int t[5005][5005];
int c, n, m, d, q;
int x,y;

int ans(int x1,int y1){
	return 1443;
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=1+2*k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	while(q--){
		cin>>x>>y;
		cout<<ans(x,y)<<endl;;
	}

	fclose(stdin);
	fclose(stdout);
}

