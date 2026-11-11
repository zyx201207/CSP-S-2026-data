#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N=5e5+10;
int a[N];
int pre[N];
int n,m;

int cnt(int x){
    int ans=0;
    ans+=pre[x-1];
    ans+=(a[x]-a[x-1])*(x-1);
    return ans;
}

signed main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(i==1) {pre[i]=0;continue;}
        else pre[i]=cnt(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(pre[i]<=m){
            ans=i;
        }
        else break;
    }
    cout<<ans;
return 0;
}
