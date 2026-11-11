#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10010000];
long long maxn;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(a[i],maxn);
        }
        cout<<maxn;
        return 0;
    }
    if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max((a[i]&a[j]),maxn);
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n){
            maxn=a[1];
        for(int i=2;i<=n;i++){
            maxn&=a[i];
        }
        cout<<maxn;
        return 0;
    }
    if(m==n-1){
        long long ts;
        ts=a[1];
        for(int i=2;i<=n;i++){
            ts&=a[i];
        }
        for(int i=1;i<=n;i++){
            maxn=max((ts&a[i]),maxn);
        }
        cout<<maxn;
        return 0;
    }
    cout<<a[n];
    return 0;
}
