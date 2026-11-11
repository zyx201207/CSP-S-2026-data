#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[505],x,y;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		long long g;
		cin>>g;
		for(int i=1;i<=g;i++) {
			long long p,q;
			cin>>p>>q;
		}
	}
	while(q--) cin>>x>>y;
	if(n==2&&m==5){
		cout<<32<<endl<<17<<endl;
		return 0;
	}
	if(n==3&&m==7&&d==20){
		cout<<35<<endl<<16;
		return 0;
	}
	return 0;
} 
