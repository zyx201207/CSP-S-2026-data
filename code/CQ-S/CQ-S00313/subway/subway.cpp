#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,x,y) for(int i=x;i<=y;++i)
#define ff(i,x,y) for(int i=x;i>=y;--i)
#define clean(arr,val) memset(arr,val,sizeof(arr))
#define fi first
#define se second
#define lb(x) (x&-x)
#define bp(x) __builtin_popcount(x)
#define endl '\n'
const int N=5e5+5; 
int c,m,n,k,d,q,jc[N],g[N][N];
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	f(i,1,m){cin>>jc[i];}
	f(i,1,n){
		int k;cin>>k;
		if(k==2){cin>>a1>>w1>>a2>>w2;}
		g[a1][a2]=g[a2][a1]=min(g[a1][a2],w1+w2);
	}
	f(i,1,q){
		int u,v;
		cin>>u>>v;
		cout<<g[u][v]<<endl;
	} 
	return 0;
}
