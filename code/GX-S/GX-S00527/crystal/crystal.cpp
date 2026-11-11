#include<bits/stdc++.h>
using namespace std;
long long a[1000005],sum[1000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    long long p=1;
    for(p;p<=n;p++){
        if(a[p]*p-sum[p]>m){
            p--;
            break;
        }
    }
    for(int i=1;i<=n-p;i++){
        if(a[i+p]*p-(sum[i+p]-sum[i])<m){
            for(p;p<=n-i;p++){
                if(a[i+p]*p-(sum[i+p]-sum[i])>m){
                    p--;
                    break;
                }
            }
        }
    }
    cout<<p;
    return 0;
}
