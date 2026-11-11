#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int s[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int maxn=1;
    for (int i=2;i<=n;i++){
        int l=1,r=i,mid;
        while (l<r){
            mid=(l+r)/2;
            if ((i-mid)*a[i]-(s[i-1]-s[mid-1])>m){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        // cout<<l<<" ";
        maxn=max(maxn,i-l+1);
    }
    // cout<<"\n";
    cout<<maxn<<"\n";
    return 0;
}