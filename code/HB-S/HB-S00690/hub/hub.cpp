#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N=505,M=2005;
int e[M][M];
int c,n,m,d,q,x,y;
int t[500085],k,a,tt;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	IOS;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) {
		cin>>t[i];
	}
	for(int i=1;i<=n;++i) {
		cin>>k;
		for(int j=1;j<=k;++j) {
			cin>>a>>tt;
			if(m<=1000) {
				e[m+i][a]=tt;
			    e[a][m+i]=tt;
			}
		}
	}
	while(q--) {
		cin>>x>>y;
		int res=e[x][y],ans=t[x]+t[y];
		cout<<res+ans<<'\n';
	}
	return 0;
}
