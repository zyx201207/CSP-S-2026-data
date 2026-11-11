#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200010],cnt=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
            cin>>a[i];
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            cnt=max(cnt,a[i]&a[j]);
        }
    }
    cout<<cnt;
    return 0;
}