#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    long long k=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==m){
        k=a[1];
        for(int i=2;i<=n;i++){
            k&=a[i];
        }
        cout<<k;
        return 0;
    }
    if(n>2000){
        sort(a+1,a+1+n);
        cout<<a[n-m+1];
        return 0;
    }
    long long h=0;
    if(m==2){
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                h=max(h,a[i]&a[j]);
            }
        }
    }
    else{
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                for(long long k=j+1;k<=n;k++){
                    h=max(h,a[i]&a[j]&a[k]);
                }
            }
        }
    }
    cout<<h;
    return 0;
}

