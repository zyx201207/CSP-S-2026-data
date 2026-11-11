#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 200010;

int n,m,a[MAXN];
int ans=-1;

void dfs(int layer,int val,int lim){
	if(val<ans)return;
	if(layer==m){
		if(ans<val)ans=val;
	}
	for(int i=lim+1;i<=n;i++){
		dfs(layer+1,val&a[i],i);
	}
	return;
}

signed main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	if(m==n){
		int res=a[1];
		for(int i=1;i<=n;i++)res&=a[i];
		cout<<res;
		return 0;
	}
	
	dfs(0,0x7fffffff,0);
	
	cout<<ans;
	
	return 0;
}

