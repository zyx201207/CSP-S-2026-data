#include<bits/stdc++.h>
using namespace std;
int c[200009];
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n==m){
        int ans=c[1];
        for(int i=2;i<=n;i++){
            ans&=c[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(c[i],ans);
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                ans=max(c[i]&c[j],ans);
            }
        }
        cout<<ans;
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(c[i],ans);
    }
    cout<<ans;
    return 0;
}
