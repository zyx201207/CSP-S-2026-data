#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=1e8+5;
ll n,m;
ll a[MAXN];
/*
ll ans=-1;

bool check(int x){
    ll ma[MAXN];
    ll sum=0;
    ll cnt=0;
    ll num=0;
    for(int i=0;i<n;i++){
        if(x-a[i]<0){
            ma[num]=x-a[i];
            sum+=abs(x-a[i]);
            cnt++,num++;
        }
    }
    if(sum<=m){
        if(ans>=cnt){
            return false;
        }else{
            ans=cnt;
            return true;
        }
    }else{
        ll o=m;
        ll pum=0;
        sort(ma,ma+num);
        for(int i=num;i>=0;i--){
            if(o+ma[i]>0){
                pum++;
                o+=ma[i];
            }
        }
        if(ans>=pum){
            return false;
        }else{
            ans=cnt;
            return true;
        }
    }

}
*/

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld",&n);
    scanf("%lld",&m);
    for(ll i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    for(ll i=0;i<n;i++){
        ll sum=0;
        for(ll j=0;j<i;j++){
            sum+=abs(a[j]-a[i]);
        }
        //cout<<sum<<endl;
        if(sum==m){
            if(a[i]==a[i+1])continue;
            printf("%lld\n",i+1);
            return 0;
        }else if(sum>m){
            printf("%lld\n",i);
            return 0;
        }

    }


    return 0;
}
