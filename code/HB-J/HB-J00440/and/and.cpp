#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],MAX=0,ans=0,cnt0=0,cnt1=0,cnt2=0,cnt3=0;
map<ll,ll> mp;
void solve(){
    cin>>n>>m;
    bool f=1,flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        MAX=max(MAX,a[i]);
        ans=ans&a[i];
        if(a[i]>=4) f=0;
        if(f){
            if(a[i]==0) cnt0++;
            if(a[i]==1) cnt1++;
            if(a[i]==2) cnt2++;
            if(a[i]==3) cnt3++;
        }
        ll x=a[i];
        int cnt=0;
        do{
            x/=2;
            cnt++;
        }while(x);
        mp[cnt]++;
    }
    if(m==1){
        cout<<MAX;
    }
    else if(m==2){
        MAX=0;
        int i=1,j=1;
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                MAX=max(MAX,a[i]&a[j]);
            }
        }
        cout<<MAX;
    }
    else if(m==n){
        cout<<ans;
    }
    else if(f){
        if(cnt3>=m) cout<<3;
        else if(cnt3+cnt2>=m) cout<<2;
        else if(cnt3+cnt1>=m) cout<<1;
        else cout<<0;
    }
    else{
        ll sum=0;
        auto i=mp.end();
        for(;;i--){
            auto p=*i;
            sum+=p.second;
            if(sum>=m){
                ll wee=floor(pow(p.first,2));
                wee-=2;
                cout<<wee;
                break;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
