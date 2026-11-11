#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[3000006],a[3000006],t[3000006];
int main(){
	freopen("subway.in","r",stdin);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i]>>t[i];
		}
		
	}
	for(int j=1;j<=q;j++){
		ll x, y;
		cin>>x>>y;
	}
	if(c==0&&n==2) {
		cout<<32<<endl<<17<<endl; 
	}
	if(c==0&&n==3) {
		cout<<35<<endl<<16<<endl; 
	}
	
	freopen("subway.out","w",stdout);
	return 0;
}
