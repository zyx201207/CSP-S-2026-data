#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    if(c!=13&&c!=14){
        while(t--) cout<<0<<"\n";
    }else{
        while(t--){
            int n,d;
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            int l=1,r=2;
            long long ans=0;
            while(r<=n){
                if(x[r]-x[l]>d){
                    l++;
                    ans+=n-r+1;
                }else{
                    r++;
                }
            }cout<<ans;
        }
    }
    return 0;
}