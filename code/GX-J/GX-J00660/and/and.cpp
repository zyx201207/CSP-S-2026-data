#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m;
cin>>n>>m;

for(int i=1;i<=n;i++){
    cin>>a[i];
}

if(m==1){
    long long ans=-999;
    for(int i=1;i<=n;i++)ans=max(ans,a[i]);
    cout<<ans;
    return 0;
}
else if(m==n){
    long long ans=a[1];
    for(int i=2;i<=n;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
else if(m==2){
    long long ans=-999;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(ans,(a[i]&a[j]));
        }
    }
    cout<<ans;
    return 0;
}

return 0;
}
