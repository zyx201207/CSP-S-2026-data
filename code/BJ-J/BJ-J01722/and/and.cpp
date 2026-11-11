#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll num;
    string to;
}a[200001];
ll n,m,ans,cnt[31],mx,le;
string trans(ll k){
    string res="";
    while (k){
        if (k%2==0) res+='0';
        else res+='1';
        k/=2;
    }
    while (res.size()<le) res+='0';
    reverse(res.begin(),res.end());
    return res;
}
ll trl(ll k){
    ll cnt=0;
    while (k){
        cnt++;
        k/=2;
    }
    return cnt;
}
bool cmp(node x,node y){return x.to>y.to;}
void clr(ll x){
    for (ll i=1;i<=n;i++) a[i].to[x]='0';
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (ll i=1;i<=n;i++){
        cin>>a[i].num;
        mx=max(a[i].num,mx);
    }
    le=trl(mx);
    for (ll i=1;i<=n;i++){
        a[i].to=trans(a[i].num);
        for (ll j=0;j<a[i].to.size();j++)
        if (a[i].to[j]=='1') cnt[j]++;
    }
    for (ll i=0;i<a[1].to.size();i++) if (cnt[i]<m) clr(i);
    sort(a+1,a+n+1,cmp);
    ans=a[1].num;
    for (ll i=2;i<=m;i++) ans&=a[i].num;
    cout<<ans;
    return 0;
}