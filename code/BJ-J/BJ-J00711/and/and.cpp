#include<bits/stdc++.h>
using namespace std;
long long a[200005],dp[200005];
long long maxx=-1e9;
long long g = pow(2,31)-1;
long long n,m;
void dfs(int x,long long cnt,long long ans){
    if(x > n)
        return;
    if(n-x < m-cnt)
        return;
    if(cnt == m){
        maxx = max(ans,maxx);
        return;
    }
    dfs(x+1,cnt,ans);
    dfs(x+1,cnt+1,ans&a[x]);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	a[0] = g;
    dfs(0,0,g);
    cout<<maxx<<endl;
    return 0;
}
