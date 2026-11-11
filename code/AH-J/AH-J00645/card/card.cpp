#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[300005],n,m,a[500005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++){
        vector<ll>table;
        for(ll j=i;j<=n;j++){
            bool f=1,pos=0;
            for(ll k=0;k<table.size();k++){
                if(table[k]==a[j]){
                    f=0;
                    pos=k;
                    break;
                }
            }
            if(f==0){
                for(ll k=pos;k<table.size();k++)table.pop_back();
            }
            else if(f==1)table.push_back(a[j]);
        }
        for(ll j=0;j<table.size();j++){
            cnt[table[j]]++;
        }
    }
    for(ll i=1;i<=m;i++)printf("%lld ",cnt[i]);
    return 0;
}
