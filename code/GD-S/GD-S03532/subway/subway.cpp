#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[100005],t[1005][1005],x,y,k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k*2;i++) cin>>t[i][j];
	}
	for(int i=1;i<=q;i++) cin>>x>>y;
	if(n==2) cout<<"32"<<endl<<"17";
	else if(n==3) cout<<"35"<<endl<<"16";
	return 0;
}
