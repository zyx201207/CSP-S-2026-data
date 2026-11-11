#include<bits/stdc++.h>
using namespace std;
long long a[500001],c[500001],q[500001];
long long n=0,m=0;
long long l=0,t=0,ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        c[i-1]=a[i]-a[i-1];
    }
    for(int i=n;i>=2;i--){
        q[i-1]=c[i-1]+q[i];
    }
    for(int i=1;i<=n;i++){
        l++;
        t+=l*c[i];
        while(t>m){
            ans=max(ans,l);
            t-=(q[i-l]-q[i]);
            l--;
        }
    }
    ans=max(ans,l);
    cout<<ans;
    return 0;
}
