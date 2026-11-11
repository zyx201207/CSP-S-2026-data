#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[101010];
ll cnt[101010];
ll a1[101010];
ll cnt1[101010];
ll p[101010];
int main()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        a1[i]=a[i];
        cnt[a[i]]++;
        cnt1[a[i]]=cnt[a[i]];
    }
    ll q=n;
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=q;j++){
                if(a[j]!=0){
                cnt[a[j]]--;
            if(cnt[a[j]]==0){
                   cnt[a[j]]+=2;
               a[q+1]=a[j];
               q+=1;
            }else{
                  ll d=0;
                  ll h=0;
                for(ll l=1;l<=q;l++){
                    if(a[l]==a[j]&&l!=j){
                        d=1;
                        h=l;
                    }
                    if(d==1&&l!=j){
                        cnt[a[l]]--;
                        a[l]=0;
                    }
                }
                a[h]=a[j];
                 q=h;
            }
        }else{
            a[q+1]=a[j];
            q+=1;
            continue;
        }
        }
         for(ll e=1;e<=m;e++){
            if(cnt[a[e]]!=0){
             p[e]++;
            }
        }
        for(ll k=1;k<=n;k++){
            a[i]=a1[i];
            cnt[a[i]]=cnt1[a[i]];
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<p[i]<<" ";
    }
}
