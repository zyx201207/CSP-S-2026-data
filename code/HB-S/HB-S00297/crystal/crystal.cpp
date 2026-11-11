#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m;
ll a[N],v[N];
set<ll>s;
map<ll,ll>k;
bool tmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s.insert(a[i]);
    }

    sort(a+1,a+1+n,tmp);
    for(int i=1;i<=n;i++){
        v[a[i]+N/2]++;
    }
    for(int i=1;i<=n;i++){
        if(k[v[a[i]+N/2]]>a[i])continue;
        else k[v[a[i]+N/2]]=a[i];
    }
    sort(v+1,v+N,tmp);
    ll maxn;
    if(s.size()==n)maxn=a[(n+1)/2];
    else maxn=k[v[1]];
    bool c=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=maxn&&c==0)continue;
        c=1;
        if(maxn-a[i]<=m){
            a[i]=maxn;
            m-=maxn-a[i];
        }
        else break;
    }
    ll num=0;
    for(int i=1;i<=n;i++){
        if(a[i]==maxn)num++;
    }
    cout<<num;
    return 0;
}
