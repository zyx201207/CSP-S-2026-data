#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500009];
ll s[500009];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int j=0,s=0,ans=0,z=0;
        for(;j<n;j++){
            if(a[0]+k<a[j]&&z==1){
                break;
            }else if(a[0]+k<a[j]&&s==3){
                z=1;
            }else if(a[0]+k<a[j]){
                break;
            }
            s++;
        }
        if(s>=4&&a[1]+k>=a[j-1]&&z==1&&a[1]+k>=a[j-1]){
            ans++;
        }
        for(int i=0;i<n;i++){
            s--;
            int z=0;
            for(;j<n;j++){
                if(a[i+1]+k<a[j]&&z==1){
                    break;
                }else if(a[i+1]+k<a[j]&&s==3){
                    z=1;
                }else if(a[i+1]+k<a[j]) break;
                s++;
            }
            if(s==4&&z==1&&a[i+2]+k>=a[j-1]){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
