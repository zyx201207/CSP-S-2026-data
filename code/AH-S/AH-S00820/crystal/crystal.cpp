#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128_t;
void print128(i128 x){
    if(x<0){
        cout<<'-';
        x=-x;
    }
    if(x>=10){
        print128(x/10);
    }
    cout<<char(x%10+'0');
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _n,_m;
    cin>>_n>>_m;
    i128 _=1;
    i128 m=_*_m,n=_*_n;
    if(n==1){
        cout<<1;
        return 0;
    }
    vector<i128> fs(n);
    for(auto &x:fs){
        ll _x;
        cin>>_x;
        x=_x;
    }
    sort(fs.begin(),fs.end());
    i128 l=1,r=n,ans=0;
    vector<i128> lk(n),ta(n);
    for(i128 i=1;i<n;i++){
        lk[i]=lk[i-1]+_*(fs[i]-fs[i-1])*i;
    }
    for(i128 i=n-2;i>=0;i--) ta[i]=ta[i+1]+_*fs[i+1]-_*fs[i];
    l=0;
    i128 p=0,now=0,maxnow=0;
    for(i128 i=0;i<n;i++){
        if(i!=0) now=now+_*(fs[i]-fs[i-1])*(i-l);
        while(now>m && l<=i) now-=(fs[i]-fs[l]),l++;
        if(maxnow<now) maxnow=now;
        if(i-l+1>ans) ans=i-l+1;
    }
    print128(ans);
    return 0;
}
//pdboynbkls
