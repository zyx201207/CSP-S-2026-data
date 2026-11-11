#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],f[1000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long s=-1;
    for(long long i=1;i<=n;i++) if(a[i]>s) s=a[i];
    f[1]=s;
    int x=s;
    for(long long i=1;i<=n;i++) cin>>a[i];
    for(long long i=2;i<=m;i++){
        s=-1;
        for(long long j=1;j<=n;j++){
            if(a[j]>s&&a[j]!=x) s=a[j];
        }
        x=s;
        f[i]=f[i-1]&s;
    }
    cout<<f[m];
    return 0;
}
