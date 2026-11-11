#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll l;
    ll r;
    char v;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    ll L=0;
    node arr[n];
    ll a[n];
    ll nowl=0;
    for(ll i=0;i<n;i++){
        cin>>a[i]>>arr[i].v;
        arr[i].l=nowl;
        arr[i].r=nowl+a[i]-1;
        nowl+=a[i];
        L+=a[i];
    }
    ll ans=0;
    int i=0,j=n-1;
    node ni=arr[i],nj=arr[j];
    while(i<j){
        if((ni.r-ni.l)>(nj.r-nj.l)){
            node t;
            t.l=ni.l+(nj.r-nj.l+1);
            t.r=ni.r;
            t.v=ni.v;
            if(ni.v!=nj.v)ans+=nj.r-nj.l+1;
            j--;
            nj=arr[j];
            ni=t;
        }
        else if((ni.r-ni.l)<(nj.r-nj.l)){
            node t;
            t.l=nj.l;
            t.r=nj.l+(nj.r-nj.l+1)-(ni.r-ni.l+1)-1;
            t.v=nj.v;//
            if(ni.v!=nj.v)ans+=ni.r-ni.l+1;
            i++;
            ni=arr[i];
            nj=t;
        }
        else{
            if(ni.v!=nj.v)ans+=ni.r-ni.l+1;
            i++;j--;
            ni=arr[i],nj=arr[j];
        }
    }
    cout<<ans;
    return 0;
}
//9:00T1 10:45T2
