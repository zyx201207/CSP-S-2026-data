#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[500005];
struct node{
	int time;
	int x;
};
node k[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int w;
		cin>>w;
		for(int j=1;j<=w;j++){
			cin>>k[i][j].x>>k[i][j].time;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=0;
		for(int j=min(x,y);j<=max(x,y);j++){
			ans+=k[1][j].time;
		}
		cout<<ans+a[x]+a[y]<<"\n";
	}
	return 0;
}
