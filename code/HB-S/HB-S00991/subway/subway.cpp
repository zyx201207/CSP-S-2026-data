#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,a[505][25],t[505][25],x,y,ans,cnt;
struct road{
	int u,v,w;
}z[1000005];
bool cmp(road x,road y){
	return x.u<y.u;
}
int work(){
	
	return 0;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k;j++){
			for(int c=1;c<=k;c++){
				cnt++;
				z[cnt].u=a[i][j],z[cnt].v=a[i][c];
				z[cnt].w=t[i][j]+t[i][c];
		}
		}
	}
	sort(z+1,z+1+n,cmp);
	for(int i=1;i<=q;i++){
		x=0,y=0,ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		ans+=work();
		cout<<ans+t[1][x]+t[1][y]<<'\n';
	}
	return 0;
}
