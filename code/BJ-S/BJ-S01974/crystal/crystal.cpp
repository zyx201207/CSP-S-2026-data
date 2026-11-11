#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
ll n;
ll m;
const ull M=1e9;
const ll N=5e5+1;
ll sum[N];
ll a[N];
void solve1(){
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=i;j++){
            sum[i]=sum[i]+(a[i]-a[j]);
            if(sum[i]>m){
                cout<<i-1;
                return;
            }
        }
    }
    return;
}
void solve2(){
    cout<<n;
    return;
}
void solve3(){
    ull ans=0;
    for(int i=1;i<=n;i++){
        ans+=i;
        if(ans>m){
            cout<<i-1;
            break;
        }
    }
    return;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    if(m<=M){
        solve1();
    }
    else{
        ull b[n+1];
        bool t1=1,t2=1;
        for(int i=1;i<=n;i++){
            cin>>b[i];
            if(b[i]!=b[i-1]&&i!=0){
                t1=0;
            }
            if((b[i]!=b[i-1]+1&&i!=1)||(b[i]!=b[i-1]-1&&i!=1)){
                t2=0;
            }
        }
        if(t1==1){
            solve2();
        }
        if(t2==1){
            solve3();
        }
        else{
            sort(b+1,b+n+1);
            bool f=1;
            for(ull i=1;i<=n;i++){
                for(ull j=1;j<=i;j++){
                    sum[i]=sum[i]+(a[i]-a[j]);
                    if(sum[i]>m){
                        cout<<i-1;
                        f=0;
                        break;
                    }
                }
                if(f==0){
                    break;
                }
            }
        }
    }
    return 0;
}