#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans;
    cin>>n>>m;
    if(m==n){
        for(int i=1;i<=n;i++){
            int c;
            cin>>c;
            if(i==1){
                ans=c;
            }else{
                ans=ans&c;
            }

        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        ans=-1e9;
        for(int i=1;i<=n;i++){
            int c;
            cin>>c;
            ans=max(ans,c);
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        ans=-1e9;
        long long l[20002];
        for(int i=1;i<=n;i++){
            cin>>l[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int c=l[i]&l[j];
                ans=max(ans,c);
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
