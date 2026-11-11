#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],b[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    int l=1,r=n;
    while(l!=r){
        int mid=(l+r+1)/2;
        int ans=9e18;
        for (int i=mid;i<=n;i++){
            int k=a[i]*mid-(b[i]-b[i-mid]);
            if (k<ans) ans=k;
        }
        if (ans<=m) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}