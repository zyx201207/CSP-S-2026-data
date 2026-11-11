#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010],n,m,maxn;
void dfs(ll t,ll he,ll cnt){
	if(cnt>m) return;
	if(t==n){
		if(cnt==m) maxn=max(maxn,he);
		return;
	}
	dfs(t+1,he&a[t],cnt+1);
	dfs(t+1,he,cnt);
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;i++) cin>>a[i];
    dfs(0,(ll)pow(2,30)-1,0);
    cout<<maxn;
    return 0;
}
