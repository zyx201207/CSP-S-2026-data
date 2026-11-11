#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[100001];
    cin>>n>>m;
    if(m==1){
        int ans=-1;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(x>ans)ans=x;
        }
        cout<<ans;
        return 0;
    }
    else if(n==m){
        int ans;
        cin>>ans;
        for(int i=2;i<=n;i++){
            int x;
            cin>>x;
            ans=ans&x;
        }
        cout<<ans;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int k=a[i]&a[j];
                if(k>ans){
                    ans=k;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
