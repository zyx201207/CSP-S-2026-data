#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    int n,m,k=1,z,ans;
    cin>>n>>m;
    int a[200005];
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    int o=a[n];
    while(o!=1){
        ++k;
        o/=2;
    }
    int maxA=int(pow(2,k));
    for(z=n;a[z]>=maxA;z--) a[z]=0;
    ans=a[z];
    for(int i=0;i<m;++i){
        ans=ans&a[z-i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}