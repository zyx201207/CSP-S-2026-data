#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;

namespace shizuru_nakatsu{
    ll a[500005],m;
    int n;
    void init(){
        
    }
    void my_love(){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        int l=1;ll pres=0;
        int ans=0;
        for(int r=0;r<=n;){
            r++;if(r>n)break;
            pres+=(r-l)*(a[r]-a[r-1]);
            while(pres>m){
                pres-=a[r]-a[l];
                l++;
            }
            ans=max(ans,r-l+1);
        }
        cout<<ans;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int T=1;
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // cin>>T;
    while(T--){
        shizuru_nakatsu::init();
        shizuru_nakatsu::my_love();
    }
    return 0;
}