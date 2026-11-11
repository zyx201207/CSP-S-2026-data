#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],n,m,ans;
void dfs(int step,int cnt,int sum){
    if(step==n+1){
        if(cnt==m){
            ans=max(ans,sum);
            cout<<sum<<" ";
        }
        return;
    }
    if(m<cnt) return;
    if(cnt!=0){
		int x=(sum&a[step]);
		dfs(step+1,cnt+1,x);
	} else{
		int y=a[step];
		dfs(step+1,cnt+1,y);
	}
    dfs(step+1,cnt,sum);
}
signed main(){
    freopen("and1.in","r",stdin);
    freopen("and1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0,0);
    cout<<ans;
    return 0;
}

