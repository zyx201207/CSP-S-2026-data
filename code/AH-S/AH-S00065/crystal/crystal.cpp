#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],k,f[500005],s;
double t;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    ll o=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) o=1;
        t+=a[i];
    }
    if(o==0){
        f[1]=0;
        for(ll i=2;i<=n;i++) f[i]=f[i-1]*2+(a[i]-a[i-1]);
        for(ll i=1;i<=n;i++){
            if(f[i]>m){
                cout<<i-1;
                return 0;
            }
        }
    }
    t=t/n;
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        if(a[i]>t){
            if(t-a[i-1]<a[i]-t) k=i-1;
            else k=i;
            break;
        }
    }
    ll p=1;
    for(ll i=1;i<=n;i++){
        if(a[k]-a[i]>0) f[p]=a[k]-a[i],p++;
        else if(a[k]==a[i]) s++;
    }
    sort(f+1,f+p+1);
    for(ll i=1;i<=p;i++){
        if(m-f[i]>0){
            m-=f[i];
            s++;
        }else{
            break;
        }
    }
    cout<<s;
    return 0;
}
