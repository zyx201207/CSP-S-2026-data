#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans=0;
    long long a[1000000005];
    long long diff[10000000005];
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(int i=m;i>=0;i--){
        if(a[i]<a[i+1]){
            a[i]+=1;
            continue;
        }
    }
    for(int i=1;i<=n;i++){
        diff[i]=a[i]-a[i-1];
        if(diff[i]==0){
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}