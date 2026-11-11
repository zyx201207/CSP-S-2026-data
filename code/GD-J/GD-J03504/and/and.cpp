#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,ans,a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=30;~i;--i){
		int cnt=0,v=ans|1<<i;
		for(int j=1;j<=n;++j)if((a[j]&v)==v)++cnt;
		if(cnt>=m)ans=v;
	}
	cout<<ans<<'\n';return 0;
}
