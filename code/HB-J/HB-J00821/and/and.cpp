#include <bits/stdc++.h>
using namespace std;
long long a[200000];
long long k[10000001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long ans;
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(long long i=0;i<n-1;i++){
        k[i]=a[i+1]-a[i];
    }
    long long minlen=999999;
    long long minid;
    for(long long i=0;i<n-1;i++){
        if(minlen>k[i]){
            minlen = k[i];
            minid=i;
        }
    }
    ans=a[minid]&a[minid+1];
    cout<<ans<<endl;
}
