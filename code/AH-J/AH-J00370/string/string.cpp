#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
struct node{
    ll s;
    char c;
}f[200005],z[200005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    ll si=0;
    for(ll i=1;i<=n;i++){
        ll s;
        char c;
        cin>>s>>c;
        z[i]={s,c};
        si+=s;
    }
    ll k=0;
    for(ll i=1;i<=n;i++){
        if(z[i].c==f[k].c){
            f[k].s+=z[i].s;
        }else{
            f[++k]=z[i];
        }
    }
    ll sum=0,l=1,r=k;
    while(l<r){
        if(f[l].s>f[r].s){
            if(f[l].c!=f[r].c){
                sum+=f[r].s;

            }
            f[l].s-=f[r].s;
            r--;
        }else{
            if(f[l].c!=f[r].c){
                sum+=f[l].s;

            }
            f[r].s-=f[l].s;
            l++;
        }
    }
    cout<<sum;
    return 0;
}
