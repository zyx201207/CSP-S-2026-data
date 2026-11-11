#include<bits/stdc++.h>
using namespace std;
long long a[200100];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==2){
        long long ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(a[i]&a[j],ans);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        long long ans;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        long long ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        cin>>a[1];long long ans1=a[1];
        for(int i=2;i<=n;i++){
            cin>>a[i];ans1=ans1&a[i];
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
                int s=1,o=0;
            for(int i=1;i<=20;i++){
                s*=2;
                if(s>a[i]){
                    o=i;
                    break;
                }
            }
            ans=max(ans1|(((1<<o)-1)^a[i]),ans);
        }
        cout<<ans<<" ";
        return 0;
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    cout<<ans;
    // 100|101=101 youyige1jiushi1 100&101=100 youyigeshi0jiushi0 100^101=1 011^101=110 butongwei1,xiangtongwei0
    return 0;
}
//12*4+100+20+10+5=183
