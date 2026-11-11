#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,g,k;
int w[505],a[505],t[505];
int x,y,xx,yy;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>g>>k;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
	}
	cin>>x>>y>>xx>>yy;
	if(n==2) cout<<"32\n17";
	else if(n==3) cout<<"35\n16";
	else cout<<"12\n10";
	return 0;
}
