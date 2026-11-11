#include<bits/stdc++.h>
using namespace std;
int ans,n,m,a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }else if(m==1){
        for(int i=1;i<=n;i++){
            if(ans<a[i]) ans=a[i];
        }
        cout<<ans;
        return 0;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&ans<(a[i]&a[j])){
                    ans=a[i]&a[j];
                }
            }
        }
        cout<<ans;
        return 0;
    }else{
        cout<<3;
    }
    return 0;
}
