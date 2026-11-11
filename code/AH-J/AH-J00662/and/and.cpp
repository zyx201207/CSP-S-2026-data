#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long n,m;
long long ans=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }
    if(m==n){
        ans=a[1];
        for(int i=1;i<=n;i++)ans&a[i];
        cout<<ans;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;i<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    if(m==n-1){
            int o=a[1],p=a[2];
        for(int i=1;i<=n-1;i++){
            o=o&a[i];
        }
        for(int i=2;i<=n;i++){
            p=p&a[i];
        }
        ans=max(o,p);
        cout<<ans;
    }
    return 0;
}
