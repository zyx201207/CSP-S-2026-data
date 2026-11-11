#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#define ll long long
using namespace std;

const int maxn = 2e5+10;
ll a[maxn];
ll m,n,ans=-0x3f3f3f3f;

void dfs(int u,ll tot,ll num){
	if(tot==m) {
		ans=max(ans,num);
		return ;
	}
	if(n-u<m-tot) return ;
	if(u>n) return ;
	for(int i=u+1;i<n;i++){
		if(tot==0) dfs(i,2,a[u]&a[i]);
		else dfs(i,tot+1,num&a[i]);
	}
	dfs(u+1,tot,num);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m==1){
		ll aa=-1;
		for(int i=0;i<n;i++) aa=max(aa,a[i]);
		cout<<aa<<endl;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
}

