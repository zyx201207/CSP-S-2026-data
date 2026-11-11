#include <bits/stdc++.h>
using  namespace std;
long long n,m,a[10000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long max=0;
    for(long long i=0;i<n-m;i++){
        for(long long j=i;j<n-m;j++){
            long long b=a[j];
            b=b&a[j+1];
            b=b&a[j+2];
            if(b>max) max=b;
        }
    }
    cout<<max;
    return 0;
}
