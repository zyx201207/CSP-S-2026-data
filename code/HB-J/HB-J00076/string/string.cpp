#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, ans, idx=1;
int a[2000005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        for(int j=idx;j<=idx+x-1;j++)
            a[j]=y-'a';
        idx+=x;
    }
    for(int i=1,j=idx-1;i<j;i++,j--)
        if(a[i]!=a[j])
            ans++;
    cout<<ans;
    return 0;
}
