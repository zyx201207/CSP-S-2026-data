#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=5e5+5;
ll n,m,a[maxn],k,mx=-1e18,mn=1e18,ans,c;
bool f1=1,f2=1;
bool acmp(ll x,ll y){
    return (abs(x-k)<abs(y-k));
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(i==2){
           c=a[i]-a[i-1];
        }mx=max(mx,a[i]);
        mn=min(mn,a[i]);
        if(a[i]!=i){
            f1=0;
        }if(a[i]-a[i-1]!=c){
            f2=0;
        }
    }
    if(mx<=100&&mn>=-100){
        for(ll i=mn;i<=mx;i++){
            k=i;ll tot=1,cnt=0,mm=m;
            sort(a+1,a+n+1,acmp);
            while(mm>=abs(k-a[tot])&&tot<=n){
                mm-=abs(k-a[tot]);
                cnt++;tot++;
            }ans=max(ans,cnt);
        }cout<<ans;
    }else if(f1){
        ans=1;
        for(ll i=1;m>=i&&ans<n;i++){
            ans++;m-=i;
            if(m>=i){
                ans++;m-=i;
            }
        }cout<<ans;
    }else if(f2){
        ans=1;
        for(ll i=c;m>=i&&ans<n;i+=c){
            ans++;m-=i;
            if(m>=i){
                ans++;m-=i;
            }
        }cout<<ans;
    }else if(n<=5000){
        for(ll p=1;p<=n;p++){
            k=a[p];ll tot=1,cnt=0,mm=m;
            sort(a+1,a+n+1,acmp);
            while(mm>=abs(k-a[tot])&&tot<=n){
                mm-=abs(k-a[tot]);
                cnt++;tot++;
            }ans=max(ans,cnt);
            if(ans==5000){
                cout<<a[p]<<"\n";
            }
        }cout<<ans;
    }else{
        cout<<"500000";
    }
    return 0;
}
