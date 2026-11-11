#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200007],b[200007],s[200007],maxn,maxans;
bool xza;
bool _find(ll x){
    for(ll i=0;i<=31;i++){
        if(pow(2,i)-1==x) return 1;
    }
    return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    maxn=0,s[0]=0,xza=1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        if(i==1) s[i]=a[i];
        if(i>1) s[i]=(s[i-1]&a[i]);
        if(a[i]>maxn) maxn=a[i];
        if(!_find(a[i])) xza=0;
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==2){
        ll ans=0;
        for(ll i=1;i<n;i++){
            for(ll j=i+1;j<=n;j++){
                if((a[i]&a[j])>ans) ans=a[i]&a[j];
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        cout<<s[n];
        return 0;
    }
    if(xza){
        sort(b+1,b+n+1);
        cout<<b[n-m+1];
        return 0;
    }
    maxans=0;
    for(ll mask=1;(1<<mask)<=n;mask++){
        ll cnt=0,ans=0;
        for(ll i=1;i<=n;i++){
            if((mask>>(i-1))&1){
                cnt++;
                ans+=a[i];
            }
        }
        if(cnt==m){
            if(ans>maxans) maxans=ans;
        }
    }
    cout<<maxans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
