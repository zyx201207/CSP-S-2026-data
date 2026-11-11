#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],h[500050],s,k,l=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=i){
            s=0;
            break;
        }
    }
    k=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=k){
            l=0;
            break;
        }
    }
    if(s){
        long long f=0;
        for(int i=1;i<=n;i++){
            f=f+i;
            if(m<f){
                cout<<i;
                return 0;
            }
        }
    }
    if(l){
        long long f=0;
        for(int i=1;i<=n;i++){
            f=f+i*k;
            if(m<f){
                cout<<i;
                return 0;
            }
        }
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n-1;i++){
        h[n]+=a[n]-a[i];
    }
    for(int i=n-1;i>=1;i--){
        h[i]=h[i+1]-i*(a[i+1]-a[i]);
    }
    for(int i=n;i>=2;i--){
        for(int j=1;j<=n-i+1;j++){
            if(h[i]<=m){
                cout<<i;
                return 0;
            }
            h[i]=h[i]-(a[i+j-1]-a[1+j-1])+(i-1)*(a[i+j]-a[i+j-1]);
        }
    }
    cout<<1;
    return 0;
}
