#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ma=0,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cnt=a[1];
    for(int i=1;i<=n;i++){
        cnt=a[i];
        for(int j=i;j<=i+m-1;j++){
            cnt=cnt&a[j];
        }
        ma=max(ma,cnt);
    }
    cout<<ma;
    return 0;
}
