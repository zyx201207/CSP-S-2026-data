#include<bits/stdc++.h>
using namespace std;
long long n,m,a[555555];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //X X XXX      X.X.XXX.
    //XX X XXX     XX.X.XXX.
    //XX X XXXX    XX.X.XXXX.
    //XX XX XX XXX XX.XX.XX.XXX.
    //XXX          XXX.
    //XXXX         XXXX.
    //XXX XXX      XXX.XXX.
    //XXXXX        XXXXX.
    //XXXXXX       XXXXXX.
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    long long q,ans=1;
    if(n%2!=0) q=(n+1)/2;
    else q=n/2;
    sort(a+1,a+n+1);
    long long OvO=m;
    for(long long i=1;i<=OvO;i++){
        for(long long j=q+1;j<=n;j++){
            if(a[q]==a[j]) ans++;
            if(a[q]<a[j]) break;
        }
        for(long long j=1;j<q;j++){
            if(a[q-j+1]==a[q-j]) ans++;
            else {
                if(m<=0) break;
                long long x=a[q-j+1]-a[q-j];
                if(m-x<0) break;
                else m-=x,a[q-j]+=x;
                if(a[q-j+1]==a[q-j]) ans++;
            }
        }
        if(m<=0) break;
    }
    cout<<ans;
    return 0;
}
//AC AC AC AC AC WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA
