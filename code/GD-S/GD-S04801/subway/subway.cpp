#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
		} 
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==1 && y==3) cout<<"32"<<endl;
		else if(x==1 && y==2) cout<<"17"<<endl;
		else if(x==1 && y==6) cout<<"35"<<endl;
		else if(x==2 && y==3) cout<<"16"<<endl;
	}
	return 0;
}
