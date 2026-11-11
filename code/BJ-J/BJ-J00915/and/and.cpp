#include<bits/stdc++.h>
using namespace std;
long long f[200005],n,m,a[200005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(long long i=1;i<=n;i++){
        for(long long j=min(i,m);j>=1;j--){
            f[j]=max(f[j],(j==1)?a[i]:f[j-1]&a[i]);
        }
    }
    cout<<f[m];
}
