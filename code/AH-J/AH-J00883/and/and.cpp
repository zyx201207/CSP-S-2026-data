#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,m,a[N],b[35],ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    int pos=n;
    for(int i=30;i>=0;i--){
        for(int j=1;j<=pos;j++){
            if(a[j]>=(1<<i)){
                b[i]++;
                a[j]-=(1<<i);
            }
        }
        if(b[i]>=m){
            ans+=(1<<i);
            pos=b[i];
        }
    }
    cout<<ans;
    return 0;
}
