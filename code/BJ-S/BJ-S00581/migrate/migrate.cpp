#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll C_IN,t;
    cin>>C_IN>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=0;i<n-3;i++){
            if(a[i+3]-a[i]>d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d){
                ans++;
                int i1=i;
                while(1){
                    if(i1+1<n&&a[i1+1]-a[i1]<=d&&a[i1+1]-a[i1++-1]>d){
                        ans++;
                    }
                    else break;
                }i1=i-3;
                while(1){
                    if(i1-1>=0&&a[i1]-a[i1-1]<=d&&a[i1+1]-a[i1---1]>d){
                        ans++;
                    }else break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
