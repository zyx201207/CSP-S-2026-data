#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN=5e5+5;

int n,m,a[MAXN];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    sort(a+1,a+n+1);

    int front=1,ans=1,cost=0;
    for(int i=2;i<=n;i++){
        cost+=(a[i]-a[i-1])*(i-front);
        while(front<i && cost>m)    front++,cost-=(a[i]-a[front]);
        ans=max(ans,i-front+1);
    }
    cout<<ans<<'\n';

    return 0;
}
