#include<bits/stdc++.h>
#define qwq return 0;
#define int long long
using namespace std;
int n,m,a[100005],v[100005],ans;

void dfs(int cnt,int y){
	if(y==m){
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			if(!cnt&&!y) dfs(a[i],y+1);
			else dfs(cnt&a[i],y+1);
			v[i]=0;
		}
	}
}
/*5 3
31 3 1 15 7*/

//7
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0);
	cout<<ans;
	qwq
}
//Trick||Treat!
//RP++
//Ô¤¼Æ10%pts
//O(n^m) 
