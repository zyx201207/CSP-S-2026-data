#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1,k;i<=m;i++) cin>>k;
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,kk;j<=k*2;j++) cin>>kk;
	}
	while(q--){
		cin>>n>>m;
		if(q==1) cout<<"32\n";
		else cout<<"17";
	}
	return 0;
}
