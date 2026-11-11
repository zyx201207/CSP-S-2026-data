#include<bits/stdc++.h>
using namespace std;
#define int long long
struct line{
	int a,t;//经过的站，该站站厅走到这条线路的站台的时间 
}l[505];
struct station{
	int w;//每站入口到站厅的时间
	int toline[21],tl[21],cur=0;
}st[500005];
int c,n,m,d,q;//线路数，站数，每站线数限制，询问次数 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>st[i].w;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>l[i].a>>l[i].t;
			st[l[i].a].toline[++st[l[i].a].cur]=l[i].t;
			st[l[i].a].tl[st[l[i].a].cur]=i;
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		cout<<st[s].w+st[s].toline[1]+st[e].toline[1]+st[e].w<<endl; 
	}
	return 0;
}
