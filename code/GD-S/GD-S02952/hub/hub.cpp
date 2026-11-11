#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
struct st{
	int w;
}zhan[MAXN];
struct lu{
	int k,t;
}luxian[MAXN];
int c,n,m,d,q;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>zhan[i].w;
	}
	for(int i=1;i<=n;i++){
		int nn;cin>>nn;
		for(int j=1;j<=n;j++){
			cin>>luxian[j].k>>luxian[j].t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		
	}
	return 0;
}
