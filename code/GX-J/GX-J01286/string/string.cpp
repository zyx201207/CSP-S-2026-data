#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct STR{
    ll a;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    STR sa[n+1];
    for(ll i=1;i<=n;i++){
        cin>>sa[i].a>>sa[i].c;
    }
    ll s=0;
    /*string str="";
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=sa[i].a;j++){
            str+=sa[i].c;
        }
    }
    for(ll i=0;i<str.size()/2;i++){
        if(str[i] != str[str.size()-i-1]) s++;
    }*/
    ll l=1,r=n,kl=sa[1].a,kr=sa[n].a;
    while(l<r){
        if(sa[l].c == sa[r].c){
            ll ks=min(kl,kr);
            kl -= ks;
            kr -= ks;
        }
        else{
            if(kl>=kr){
                s+=kr;
                kl-=kr;
                kr = 0;
            }
            else{
                s+=kl;
                kr -= kl;
                kl = 0;
            }
        }
        if(kl==0){
            l++;
            kl = sa[l].a;
        }
        if(kr==0){
            r--;
            kr = sa[r].a;
        }
    }
    cout<<s;
    return 0;
}

