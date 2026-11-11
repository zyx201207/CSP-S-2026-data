#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],b[500005],n,m;
bool cmp(int x,int y){
    return x>y;
}
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=i-1;j>=1;j--){
            if(cnt+(a[i]-a[j])>m) break;
            b[i]++;
            cnt+=a[i]-a[j];
        }
    }
    sort(b+1,b+n+1,cmp);
    cout<<b[1]+1;


    return 0;
}
