#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=2e5+10;
ll n,m,a[N];
bool flaga,flagb;
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    /*
    for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=i-1) flagb=false;
            else if(log2(a[i]+1)!=int(log2(a[i]+1))) flaga=false;
    }
    int mx=-INF;
    if(m==1){
        for(int i=1;i<=n;i++) mx=max(a[i],mx);
        cout<<mx;
    }
    */
    ll mx=-INF;
    for(int i=1;i<=n;i++) cin>>a[i];
    /*if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++) mx=max(mx,a[j]&a[i]);
        }
        cout<<mx;
        return 0;
    }*/
    sort(a+1,a+1+n,cmp);
    ll x=a[1];
    for(int i=2;i<=m;i++){
            ll t=x&a[i];
            if(t==0) x=a[i],m++;
//            cout<<x<<" "<<a[i]<<" ";
//            cout<<t<<"\n";
            x=x&a[i];
    }
    cout<<x;
    return 0;
}
