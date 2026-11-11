#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int p=0;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		if(i<=2) p+=w;
	} 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cout<<1;
			int a,t;
			cin>>a>>t;
			if(p<=2) p+=t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	for(int i=1;i<=q;i++){
		cout<<p<<"\n";
	}
	return 0;
}

