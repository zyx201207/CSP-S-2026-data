#include <bits/stdc++.h>
using namespace std;
#define int long long;
int   a[200001];
signed main (){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    int cnt = 0;
    sort(a+1,a+1+n);
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= i;j++){
            cnt = max(cnt,(a[i]^a[j]));
            //cout<<a[i]<<"\n";
        }
    }
    cout<<cnt;
    return 0;
}
