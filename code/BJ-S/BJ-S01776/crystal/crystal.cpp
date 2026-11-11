#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],num[500005],fst[500005],chg[500005],s[500005],hgt[500005],x,ans,mus;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=1000000000001;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i-1]==a[i]&&i!=1){
            chg[i]=x;
            num[x]++;
        }else{
            x++;
            chg[i]=x;
            fst[x]=i;
            num[x]++;
            hgt[x]=a[i];
        }
    }
    fst[x+1]=n+1;
    ll sum_1=0;
    for(int i=1;i<=x;i++){
        s[i]=sum_1*(hgt[i]-hgt[i-1])+s[i-1];
        sum_1+=num[i];
    }
    ll t;
    for(int i=1;i<=n;i++){
        if(a[i-1]!=a[i]&&i!=1){
            mus+=(i-fst[chg[i-1]])*(a[i]-a[i-1]);
        }
        ll l=chg[i],r=x;
        while(l<r){
            ll mid=(l+r+1)>>1;
            t=s[mid]-(i-1)*(hgt[mid]-a[i])-mus;
            if(t<=m){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        ans=max(ans,fst[l+1]-i);
    }
    cout<<ans;
    return  0;
}
