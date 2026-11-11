#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1000009];
signed main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int zz;
    zz=1;
    int sum;
    sum=0;
    int ans;
    ans=1;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        while(a[i]*(i-zz+1)-sum>m){
            sum-=a[zz];
            ++zz;
        }
        ans=max(ans,i-zz+1);
    }
    cout<<ans;
    return 0;
}
