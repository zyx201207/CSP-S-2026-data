#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
using ll=long long;
ll m,a[N];
int n,ans;
int last;
int cal(int k){
    ll tot=0;
    int i=k;
    while(tot<=m && i>=1){
        tot+=a[k]-a[i];
        i--;
    }
    return k-i;
}
void solve_A(){
    ll ans=1;
    ll tot=1;
    while(tot<=m){
        ans++;
        tot=ans*1ll*(ans-1)/2;
    }
    cout<<ans-1<<endl;
}
bool chk(int k,int &ans){
    ll tot=0;
    int i=k;
    while(tot<=m && i>=1){
        tot+=a[k]-a[i];
        i--;
    }
    if(k-(i+1)+1>=last) { ans=k-i; return true; }
    return false;
}
void solve_BIG(){
    int l=0,r=n+1;
    last=1;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(chk(mid,last)) l=mid;
        else r=mid-1;
    }
    cout<<last<<endl;
}
void solve_B(){
    ll ans=1;
    ll tot=1;
    ll d=a[2]-a[1];
    while(tot<=m){
        ans++;
        tot=d*ans*1ll*(ans-1)/2;
    }
    cout<<ans-1<<endl;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool f_A=1,f_B=1;
    for(int i=1;i<=n;++i) {
        cin>>a[i]; 
        if(a[i]!=i) f_A=0;
    }
    sort(a+1,a+n+1);
    for(int i=2;i<n;++i){
        if(a[i]-a[i-1]!=a[i+1]-a[i])
            f_B=0;
    }
    if(f_A){
        solve_A();
        return 0;
    }
    if(f_B){
        solve_B();
        return 0;
    }
    if(n>5e3){
        solve_BIG();
        return 0;
    }
    
    for(int i=1;i<=n;++i){
        int temp=cal(i);
        ans=max(ans,temp);
    }
    cout<<ans<<endl;
    return 0;
}
//3:3845
//4:315275