#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ans=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1){
        cout<<a[1];
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>ans) ans=a[i];
        }
        cout<<ans;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                long long t=a[i]&a[j];
                ans=max(ans,t);
            }
        }
        cout<<ans;
    }
    else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==n-1){
        for(int i=1;i<=n;i++){
            long long x=(1<<32)-1;
            for(int j=1;j<=n;j++){
                if(i!=j){
                    x&=a[j];
                }
            }
            ans=max(ans,x);
        }
        cout<<ans;
    }
    return 0;
}
