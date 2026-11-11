#include <bits/stdc++.h>
using namespace std;
long long n,m,l=0,r,ans=1;
long long a[500005],pre[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    r=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    while(l<=r){
        long long mid=(l+r)/2,flag=0;
        for(int l1=1;l1<=n-mid+1;l1++){
            long long r1=l1+mid-1,tot=0;
            tot=mid*a[r1]-(pre[r1]-pre[l1-1]);
            if(tot<=m){
                ans=max(ans,mid);
                flag=1;
                l=mid+1;
                break;
            }
        }
        if(flag==0){
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
