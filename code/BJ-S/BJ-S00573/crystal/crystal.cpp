#include<bits/stdc++.h>
using namespace std;
long long a[500009],n,m,ans=1,need,s;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    s=1;
    long long l=1,r=1;
    for(int i=2;i<=n;i++){
        while((a[i]-a[i-1])*s+need > m && s>1){
            l+=1;
            s-=1;
            need-=(a[i]-a[l]);
        }
        r+=1;
        need+=(a[i]-a[i-1])*s;
        s+=1;
        ans=max(ans,s);
    }
    cout<<ans;
    return 0;
}
