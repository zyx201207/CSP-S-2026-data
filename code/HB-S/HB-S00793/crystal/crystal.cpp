#include<bits/stdc++.h>
#define int long long
#define F(i,l,r) for(int i=(l);i<=(r);++i)
#define F2(i,l,r) for(int i=(l);i>=(r);--i)
using namespace std;
constexpr int N=5e5+10;
int n,ans,cnt;
int m,t,a[N];
bool A=1,B=1;
inline bool check(int x){
    int num=x*(x+1)/2;
    return num<=m;
}
inline bool check2(int x,int d){
    int num=(x*(x+1))/2*d;
    return num<=m;
}
inline void solve1(){
    int l=1,r=n,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans+1;
    return;
}
inline void solve2(){
    int d=a[2]-a[1];
    int l=1,r=n,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(check2(mid,d)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans+1;
    return;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    F(i,1,n){
        cin>>a[i];
        if(A==1&&a[i]!=i) A=0;
    }
    int b=a[2]-a[1];
    F(i,3,n){
        if(a[i]-a[i-1]!=b){
            B=0;
            break;
        }
    }
    sort(a+1,a+1+n);
    if(A){
        solve1();
        return 0;
    }
    if(b){
        solve2();
        return 0;
    }
    F(i,1,n){
        cnt=1;
        t=m;
        F2(j,i-1,1){
            if(t>=a[i]-a[j]){
                ++cnt;
                t-=(a[i]-a[j]);
            }    
            else break;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}