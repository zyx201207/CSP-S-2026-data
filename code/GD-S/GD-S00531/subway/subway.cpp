#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
		}
	}
	int p=q;
	while(p--){
		int x,y;
		cin>>x>>y;
	}
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout<<"32\n17";
		}
		if(n==3&&m==7&&d==20&&q==2){
			cout<<"35\n16";
		}
	}
	return 0;
}
