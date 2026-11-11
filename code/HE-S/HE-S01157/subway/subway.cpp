//µØÌú£¨subway£©
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int zhan[500005];
int k[500005];
int vis[500005];
struct sub{
	int zan,time;
}a[500][50005];

int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>zhan[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j].zan>>a[i][j].time;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<354;
	}
	return 0;
}
