#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5e5+5;
ll n, m, a[N], b[N], l, ans;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    l=1;
    for(ll r=1;r<=n;r++){
        while(b[r]-b[l-1]-(l-1)*(a[r]-a[l-1])>m)
            l++;
        ans=max(ans, r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}