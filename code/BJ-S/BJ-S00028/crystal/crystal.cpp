#include<bits/stdc++.h>
#define ll long long
using namespace std;//reminds to ll!
ll n,m,ans;
vector<ll>s,a;
bool check(ll md){
    for(ll l=1;l<=n-md;l++){
        ll r=l+md-1;
        ll p=(s[r-1]-s[l-1]);
        ll q=a[r]*(md-1);
        if(q<=p+m)return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    a.resize(n+1);
    s.resize(n+1,0);
    a[0]=-1e12;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    ll l=1,r=n;
    while(l<=r){
        ll md=(l+r)/2;
        if(check(md))l=md+1,ans=md;
        else r=md-1;
    }
    cout<<ans;
    return 0;
}
/*
5 8
-3 -1 2 2 7
Guanzhu CR.yt_qwq Xiexiemiao
*/