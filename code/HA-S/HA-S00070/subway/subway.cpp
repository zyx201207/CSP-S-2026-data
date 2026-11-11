#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,x,y,t;
long long a,b;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>b;
		}
	}
	for(int r=1;r<=q;r++){
		cin>>x>>y;
		cout<<(y-x)*t<<'\n';
	}
	return 0;
} 


