#include <bits/stdc++.h>
#define ll long long
#define sz(a) (int)(a).size()
#define mk make_pair
#define pb push_back
#define fir first
#define sec second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define req(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
/*
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
*/
const int N=5e5+10;
ll n,m,a[N],ans=1;
bool check(ll x){
    ll cnt=m,res=0;
    req(i,n,1){
        if(a[i]<=a[x]){
            if(cnt>=a[x]-a[i])cnt-=a[x]-a[i],res++;
            //else break;
        }
    }

    if(res>=x)  return true;
    else return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    rep(i,1,n) {
        cin>>a[i];
    }
    //cout<<maxn<<" ";
    sort(a+1,a+1+n);
    ll l=1,r=n;
    while(l<=r){
            ll mid=(r-l)/2+l;
        if(check(mid)){
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }
    cout<<l-1;
    return  0;
}
/*
g++ Untitled.cpp -o Untitled -O2 -std=c++14
g++  home user Untitled.cpp -o Untitled -O2 -std=c++14
*/
