#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+10;
ll n,m,a[maxn],ans,dp[maxn],l,r;
bool check(ll x,ll y){
	if((dp[y]-dp[x-1]+m)%(y-x+1)!=0) return 0;
	int res=0;
	for(int i=x;i<=y-1;i++) res+=a[y]-a[i];
	if(res>m) return 0;
	return 1;
} 
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if(!(cin >> n >> m)) return 0;
    for(ll i=1;i<=n;i++) cin >> a[i];
    for(ll i=1;i<=n;i++) dp[i]=dp[i-1]+a[i];
    l=1,r=2;
    if(n==1){
    	cout << 1;
    	return 0;
	}
    while(l<r){
    	if(check(l,r)){
    		ans=max(ans,r-l+1);
    		if(r < n) r++;
		}else l++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

