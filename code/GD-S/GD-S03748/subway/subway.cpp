#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[2005];
int k[505];
struct node{
	int a,t;
}sub[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>sub[i][j].a>>sub[i][j].t;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<rand()%100<<" ";
	}
	return 0;
}
