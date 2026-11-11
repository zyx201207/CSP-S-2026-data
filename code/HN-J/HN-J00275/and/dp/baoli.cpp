#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans;
bool fx[200005];
void dfs(int x,int cnt){
	if(cnt>m)return;
	if(x>n){
		if(cnt!=m)return;
		bool f=0;
		int now;
		for(int i=1;i<=n;i++){
			if(!f&&fx[i])now=a[i],f=1;
			else if(fx[i])now&=a[i];
		}
		ans=max(ans,now);
		return;
	}
	dfs(x+1,cnt);
	fx[x]=1;
	dfs(x+1,cnt+1);
	fx[x]=0;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("baoli.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
