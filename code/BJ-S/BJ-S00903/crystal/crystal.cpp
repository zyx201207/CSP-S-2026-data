#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[500005],pre[500005];
ll read(){
    ll x=0,c=1;
    char ch;
    ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            c=-1;
        }
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar_unlocked();
    }
    return x*c;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    n=read();m=read();
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    ll r=1;
    while(r<=n&&a[r]*r-pre[r]<=m){
        r++;
    }
    r--;
    ll l=1;
    ll now=m-(a[r]*r-pre[r]),ans=r;
    for(ll i=r+1;i<=n;i++){
        now-=(a[i]-a[i-1])*(i-l);
        //cout<<now<<endl;
        while(now<0){
            now+=(a[i]-a[l]);
            l++;
        }
        //cout<<l<<" "<<i<<" "<<now<<endl;
        ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
