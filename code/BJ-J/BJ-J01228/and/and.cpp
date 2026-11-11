#include<bits/stdc++.h>
using namespace std;
int a[1000005];
long long mx=-10005;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,1LL*a[i]);
    }
    if(n==1) cout<<mx;return 0;
    mx=-1000;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                if(i==j) continue;
            mx=max(mx,1LL*(a[i] & a[j]));
        }
    }
    cout<<mx;
    return 0;
}
