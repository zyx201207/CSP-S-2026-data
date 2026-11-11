#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt;
ll rst[32];
ll a[422204];
ll result;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll ind=31;ind>=0;ind--){
        cnt=0;
        for(ll i=0;i<n;i++)
        {
            if(a[i]&(1<<ind)){
                cnt++;
            }
        }
        if(cnt>=m){
            rst[ind]=1;
            for(ll i=0;i<n;i++)
            {
                if(!(a[i]&(1<<ind)))
                {
                    a[i]=0;
                }
            }
        }
        else{
            rst[ind]=0;
        }
    }
    for(ll ind=0;ind<32;ind++){
        result+=rst[ind]*(1<<ind);
    }
    cout << result << "\n";
    return 0;
}
