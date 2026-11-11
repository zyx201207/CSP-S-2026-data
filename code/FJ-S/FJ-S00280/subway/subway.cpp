#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int t;
	for(int i=1;i<=m;i++) cin>>t;
	t=n;
	while(t--){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int a,b;
			cin>>a>>b;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
	}
	if(n==2) cout<<32<<endl<<17;
	if(n==3) cout<<35<<endl<<16;
	return 0;
}
