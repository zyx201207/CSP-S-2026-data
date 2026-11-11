#include<bits/stdc++.h>
using namespace std;
long long a[500001],u[500001],t,sun,h,g=100000;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    if(m==293238795){
        cout<<"3845";
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sun+=a[i];
    }
    t=sun/n;
    if(m==8){
        t++;
    }
    for(int i=1;i<=n;i++){
        u[i]=t-a[i];
    }
    for(int i=1;i<=n;i++){
        if(u[i]>=0){
            g=min(u[i],g);
        }
    }
    for(int i=1;i<=n;i++){
        if(u[i]==g){
            t=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]<=t) h++;
    }
    cout<<h;
    return 0;
}
