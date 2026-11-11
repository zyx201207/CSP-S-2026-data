/*
easy
just sort and greedy is ok

oh no
wa on sample 4
ok i know why i wa
it isn't convinced that you can just greed from the last
so you need two pointer
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,a[N],m,ans,tot;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int rp=1,lp=1;rp<=n;rp++){
        if(rp>1) tot+=(ll)(rp-lp)*(a[rp]-a[rp-1]);
        while(tot>m) lp++,tot-=a[rp]-a[lp];
        ans=max(ans,rp-lp+1ll);
    }
    cout<<ans<<'\n';
    return 0;
}
/*
code by A.Y.C.
awa
*/
