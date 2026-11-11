#include<bits/stdc++.h>
using namespace std;
long long a[500500],m,n,ans,cnt,cut;
long long b[500500],c[500500];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(m==0){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n-1;i++){
        b[i]=a[i+1]-a[i];
        cut+=b[i];
    }
    for(int i=1;i<=n;i++){
        c[i]=a[n]-a[i];
        ans+=c[i];
    }
    int v=1;
    while(ans>m){
        ans-=b[n-v]*(n-v);
        for(int i=1;i<=n;i++){
            c[i]-=b[n-v];
        }
    }
    for(int i=1;i<=n;i++){
        if(c[i]>=0)cnt++;
    }
    cout<<cnt;
    return 0;
}
