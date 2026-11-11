#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500001],s[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=0,r=i,mid;
        while(l<r){
            mid=(l+r)/2;
            if((i-mid-1)*a[i]-(s[i-1]-s[mid])<=m){
                r=mid;
            }
            else l=mid+1;
        }
        ans=max(ans,i-l);
    }
    cout<<ans;
    return 0;
}
