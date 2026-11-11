#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l=1,r,n,m,k,a[2000005],xc[2000005],qj[2000005],sb,ins=0;
bool cmp(ll a,ll b){
    return a<b;
}
int check(ll mi){
    ll u=0;
    for(int i=2;i<=mi;i++){
        u+=xc[i]*(i-1);
    }
    ll zx=u;
    for(int i=mi+1;i<=n;i++){
        u=u-(a[i-1]-a[i-mi])+xc[i]*(mi-1);
        if(u<zx){
            sb=i;
        }
        zx=min(zx,u);
    }
    if(zx==m){
        return 2;
    }else if(zx<m){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    r=n;
    sort(a+1,a+1+n,cmp);
    for(int i=2;i<=n;i++){
        xc[i]=a[i]-a[i-1];
    }
    while(l<r){
        ll mid=(l+r)/2;
        int pd=check(mid);
        if(pd==2){
            l=mid;
            break;
        }else if(pd==1){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

