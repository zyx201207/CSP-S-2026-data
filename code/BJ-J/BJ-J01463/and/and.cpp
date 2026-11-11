#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans,d;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];d=max(d,a[i]);}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++)ans=ans&a[i];
    }
    if(m==1)ans=d;
    cout<<ans;
    return 0;
}
