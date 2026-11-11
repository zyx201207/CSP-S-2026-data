#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N=2e5+10;
struct node{
    int cnt;
    char c;
}a[N];
int m,n=1,ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m;
    int tmp;
    char q;
    cin>>tmp>>q;
    a[n].cnt=tmp,a[n].c=q;
    for(int i=2;i<=m;i++){
        cin>>tmp>>q;
        if(q==a[n].c){
            a[n].cnt+=tmp;
        }else{
            n++;
            a[n].cnt=tmp;
            a[n].c=q;
        }
    }
    int l=1,r=n;
    int ll=0,rr=0;
    char l_,r_;
    while(l<r){
        if(!ll){
            ll=a[l].cnt;
            l_=a[l].c;
        }
        if(!rr){
            rr=a[r].cnt;
            r_=a[r].c;
        }
        if(l_==r_){
            if(ll==rr){
                ll=rr=0;
                l++;
                r--;
            }else if(ll>rr){
                ll-=rr;
                rr=0;
                r--;
            }else{
                rr-=ll;
                ll=0;
                l++;
            }
        }else{
            ans+=min(ll,rr);
            if(ll==rr){
                ll=rr=0;
                l++;
                r--;
            }else if(ll>rr){
                ll-=rr;
                rr=0;
                r--;
            }else{
                rr-=ll;
                ll=0;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
