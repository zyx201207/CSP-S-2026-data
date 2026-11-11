#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
const int Q=1e5+5;
int a[M];
struct P{int a,t;}l[505][M];
struct trip{int x,y;}t[Q];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)cin>>l[i][j].a>>l[i][j].t;
	}
	for(int i=1;i<=q;i++)cin>>t[i].x>>t[i].y;
	return 0;
}
