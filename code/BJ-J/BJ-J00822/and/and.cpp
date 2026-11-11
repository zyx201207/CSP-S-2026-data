#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a[200010],cnt=2147483647,sum,b,max1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        sum=cnt;
        max1=-1;
        for(int j=1;j<=n;j++){
            if(a[j]&sum>max1){
                max1=a[j]&sum;
                b=j;
            }
        }
        cnt=max1;
        a[b]=0;
    }
    cout<<cnt;
    return 0;
}
