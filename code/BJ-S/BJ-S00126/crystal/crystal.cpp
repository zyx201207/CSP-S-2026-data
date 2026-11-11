#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,used=0,l=1,stan,ans=0;
int a[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    stan=a[1];
    used=0;
    ans=1;
    for(int i=2;i<=n;i++){
        int cost=(a[i]-stan)*(i-l)+used;
        while(cost>m){
            used-=(stan-a[l]);
            l++;
            cost=(a[i]-stan)*(i-l)+used;
        }
        ans=max(ans,i-l+1);
        stan=a[i];
        used=cost;
    }
    cout<<ans;
    return 0;
}
