#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,m,a[N];
ll to(ll n,ll m){
    ll cnt=0,a[N],b[N],c[N],cct=0;
    while(1){
        a[++cnt]=n%2,n/=2;
        if(n<=0) break;
    }
    while(1){
        b[++cct]=m%2,m/=2;
        if(m<=0) break;
    }
    if(cnt<4) cnt=4;
    if(cct<4) cct=4;
    ll mx=max(cnt,cct);
    for(int i=1;i<=cnt/2;i++) swap(a[i],a[cnt-i+1]);
    for(int i=1;i<=cct/2;i++) swap(b[i],b[cct-i+1]);
    for(int i=1;i<=mx;i++){
        if(a[i]==b[i]) c[i]=1;
        else c[i]=0;
    }
    if(cct!=cnt){
        for(int i=1;i<=mx/2;i++) swap(c[i],c[mx-i+1]);
    }
    ll sum=0;
    for(int i=mx,j=0;i>=1;i--,j++){
        sum+=c[i]*pow(2,j);
    }
    for(int i=1;i<=mx;i++) a[i]=0,b[i]=0,c[i]=0;
    return sum;
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=2;i<=m;i++) a[i]=to(a[i],a[i-1]);
    cout<<a[m];
    return 0;
}
