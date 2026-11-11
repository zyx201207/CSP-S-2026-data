#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define int long long
const int N=5e5+10,M=3e5+10;
int n,m,a[N],ans[N],vis[M],cnt=1,vis2[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	REP(i,1,n) cin>>a[i],vis[a[i]]=i;
	REP(i,1,n){
		REP(j,i,n){
			ans[a[j]]++;
			j=vis[a[j]];
		}
	}
	REP(i,1,m) cout<<ans[i]<<" ";
	return 0;
}
//Trick||Treat!
