#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        sort(a+1,a+n+1);cout<<a[n];return 0;
    }
    else if(m==n){
            int ans=a[1];
        for(int i=1;i<=n;i++){
            ans=(ans&a[i]);

        }
        cout<<ans;return 0;
    }
    else if(m==2){
        int ans=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else cout<<1;
    return 0;
}
//.
