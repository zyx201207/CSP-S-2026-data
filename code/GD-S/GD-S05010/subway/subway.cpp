#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int b[500005][2];
int main(){
	freopen("","r",stdin);
	freopen("","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int luchu[m+1];
	for(int i=1;i<=m;i++)cin>>luchu[i];
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		for(int j=1;j<=a;j++){
			int x,y;cin>>x>>y;
			b[x][1]=y;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		cout<<b[x][1]+b[y][1]+luchu[x]+luchu[y]<<endl;
	}
} 
