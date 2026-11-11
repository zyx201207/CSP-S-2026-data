#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll power(ll a,ll b){
    if(b==0)
        return 1;
    ll x=power(a,b/2);
    if(b%2==0)
        return x*x;
    else
        return x*x*a;
}
vector<ll> nums,ttong,temp;
vector<vector<bool>> hvnums;
vector<vector<ll>> cjnums(64);
ll getmaxa(ll cj,ll m,vector<ll> xz){
    if(cjnums[cj].size()==0)
        return getmaxa(cj-1,m,xz);
    ll res=0;
    if(xz.size()==0&&cjnums[cj].size()>=m)
        for(auto &x:cjnums[cj])
            xz.push_back(x);
    vector<ll> temp;
    for(int i=0;i<xz.size();i++)
        if(hvnums[cj][xz[i]])
            temp.push_back(xz[i]);
    if(temp.size()>=m)
        xz=temp,res+=power(2,cj);
    if(cj==0)
        return res;
    return getmaxa(cj-1,m,xz)+res;
}
ll solve(){
    ll n,m;
    cin>>n>>m,nums=ttong=vector<ll>(n+10,0);
    hvnums=vector<vector<bool>>(64,vector<bool>(n+10,false));
    for(int i=1;i<=n;i++){
        cin>>nums[i];
        for(ll temp=nums[i],cj=0;temp!=0;temp/=2,cj++)
            if(temp%2==1)
                hvnums[cj][i]=true,cjnums[cj].push_back(i);
    }
    return getmaxa(63,m,vector<ll>(0));
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cout<<solve();
    return 0;
}