#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
using ll=long long;
const int N=1e5+5;
ll n,m,a[N],ans;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    if(n<=5000){
        rep(i,1,n){
            ll t=a[i],tm=m,res=0;
            rep(j,1,n){
                if(a[j]<t&&tm-(t-a[j])>=0){
                    tm-=(t-a[j]);
                    res++;
                }
                if(a[j]==t) res++;
            }
            ans=max(ans,res);
        }
        cout<<ans;
    }
    else{
        sort(a+1,a+n+1);
        ll mid=(1+n)>>1;
        ll t=a[mid];//t:target
        rep(i,1,n){
            if(a[i]<t&&m-(t-a[i])>=0){
                m-=(t-a[i]);
                a[i]=t;
                ans++;
            }
            else if(a[i]==t) ans++;
        }
        cout<<ans;
    }
    return 0;
}
