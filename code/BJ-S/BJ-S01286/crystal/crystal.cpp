#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0,ans=0,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1; i<=n; i++){
        sum+=(a[i+1]-a[i])*i;
        ans++;
        if(sum>m)
            break;
    }
    cout<<ans;
    return 0;
}
