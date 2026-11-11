#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll ttt[505][500005];
ll ktt[500005];
struct updown{
	ll up,down;
}ud[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ktt[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			ttt[i][a]=t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>ud[i].up>>ud[i].down;
	}
	
	return 0;
}
