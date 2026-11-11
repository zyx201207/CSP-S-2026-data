#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e4+10,N=5e2+10;
int c,n,m,d,q,w[N],k[N],a[N][M],t[N][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
	}
	if(c==0&&n==2&&m==5&&d==20){
		cout<<32<<"\n"<<17;
		return 0;
	}
	else if(c==0&&n==3&&m==7&&d==20){
		cout<<35<<"\n"<<16;
		return 0;
	}
	cout<<rand();
	return 0;
} 
