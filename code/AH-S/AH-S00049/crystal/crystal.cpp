#include<bits/stdc++.h>
using namespace std;
#define int long long
int ai[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		cin>>ai[x];
	}
	sort(ai+1,ai+n+1);
	int r=n,ans=0;
	for(int x=n;x>=1;x--){
		while(r>1&&m>0&&ai[x]-ai[r-1]<=m)r--,m-=ai[x]-ai[r];
		ans=max(ans,x-r+1);
		m+=(x-r)*(ai[x]-ai[x-1]);
	}cout<<ans;
	return 0;
}
