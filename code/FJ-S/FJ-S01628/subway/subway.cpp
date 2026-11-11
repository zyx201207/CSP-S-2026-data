#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int c,n,m,d,q,w[MAXN],k[MAXN],a[600][600],t[600][600],x[100010],y[100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		cout<<(a[i][n]+t[i][n])*4<<endl;
	}
	return 0;
}
