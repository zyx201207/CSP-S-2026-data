#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[500005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n,m; cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+1+n);

    int cnt; cnt=1;
    int now; now=0;
    int ans; ans=1;
    for(int i=2;i<=n;i++){
        now+=cnt*(a[i]-a[i-1]);
        cnt++;
        while(now>m){
            now-=a[i]-a[i-cnt+1];
            cnt--;
        }

        ans=max(ans,cnt);
    }

    cout<<ans<<endl;
    return 0;
}

/*
Oct31==Dec25?
Est Score: 100

Till then,
I'll keep struggling
Curse of justice,
you don't know

luogu635361
*/


