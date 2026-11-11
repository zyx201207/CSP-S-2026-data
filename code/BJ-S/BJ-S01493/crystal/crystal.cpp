#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int N=5e5+50;
int a[N],n,m;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int now=1;
    int nd=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i!=1)nd+=(a[i]-a[i-1])*(i-now);
        while(now<i && nd>m){
            nd-=(a[i]-a[now]),++now;
        }
        ans=max(ans,i-now+1);
    }
    cout<<ans;
    return 0;
}
