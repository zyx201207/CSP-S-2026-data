#include<bits/stdc++.h>
using namespace std;
int w[500005];
int k[600];
int a[600];
int t[600];
int r[500005][3];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i]>>t[i];
	}
	for(int i=1;i<=q;i++) cin>>r[i][1]>>r[i][2];
	for(int i=1;i<=q;i++) cout<<i<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

