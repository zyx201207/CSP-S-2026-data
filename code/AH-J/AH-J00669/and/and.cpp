#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll s,t=0;
}a[1000005];
bool cmp(const node &x,const node &y){
    if(x.t!=y.t)return x.t>y.t;
    return x.s>y.s;
}
string er(ll n){
    string c="";
    while(n){
        c=char(n%2+'0')+c;
        n/=2;
    }
    return c;
}
ll sum[1000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    string c;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i].s;
        c=er(a[i].s);
        for(ll j=0;j<c.size();j++){
            if(c[j]=='1')a[i].t++;
        }
    }
    sort(a+1,a+n+1,cmp);
    sum[1]=a[1].s;
    for(ll i=2;i<=n;i++){
        sum[i]=sum[i-1]&a[i].s;
    }
    cout<<sum[m];
    return 0;
}
