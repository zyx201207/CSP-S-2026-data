#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int i1[1005];
int ii[1005][1005],iii[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	int tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>i1[i];
	}
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		for(int j=0;j<t;j+=2){
			int x1,x2,y1,y2;
			cin>>x1>>y1>>x2>>y2;
			int x=min(x1,x2),y=max(x1,x2);
			ii[x][y]=y1;
			iii[x][y]=y2;
		}
	}for(int i=1;i<=q;i++){
		int a,b;cin>>a>>b;
		int x=min(a,b),y=max(a,b);
		if(x!=y)cout<<i1[x]+ii[x][y]+iii[x][y]+i1[y];
		else cout<<0;
	}
	return 0;
}
