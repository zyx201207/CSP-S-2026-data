#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N=2e6+10;
ll n,d,a[N],mn=9e18,cnt=0;

void dfs(ll s,ll t,ll ct){
    // cout<<s<<' '<<t<<' '<<ct<<endl;
    if(s==t){
        if(ct<mn){
            mn=ct;
            cnt=1;
            // cout<<"yes"<<endl;
        }else if(ct==mn){
            // cout<<"yes2"<<endl;
            cnt++;
        }
        return ;
    }
    ll j=upper_bound(a+s,a+t+1,a[s]+d)-a;
    // cout<<j-1<<endl;
    
    for(ll i=s+1;i<=j-1;i++){
        dfs(i,t,ct+1);
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    if(c<=10){
        while(t--){
            cin>>n>>d;
            for(ll i=1;i<=n;i++){
                cin>>a[i];
            }
            sort(a+1,a+n+1);


            ll ans=0;
            for(ll i=1;i<=n;i++){
                for(ll j=i+1;j<=n;j++){
                    mn=9e18;
                    cnt=0;
                    dfs(i,j,0);
                    // cout<<"---"<<endl;
                    // cout<<i<<' '<<j<<' '<<cnt<<endl;
                    if(cnt==2){
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }else{
        while(t--){
            cin>>n>>d;
            for(ll i=1;i<=n;i++) cin>>a[i];

            if(a[2]-a[1]>d) cout<<0<<endl;
            else{             
                if(a[3]-a[1]<=d && a[4]-a[1]>d) cout<<n-3<<endl;
                else cout<<0<<endl;
            }
        }
    }
    return 0;
}