#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+100;
int n,m,c,a[N],f[N],max_=-1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    f[1]=1;
    int j=1;
    c=m;
    for(int i=2;i<=n;i++){
        c-=(a[i]-a[i-1])+(f[i-1]-1)*(a[i]-a[i-1]);
        f[i]=(f[i-1]+1);
        while(c<0&&j<i){
            f[i]--;
            c+=(a[i]-a[j]);
            j++;
        }
       //
    }
    for(int i=1;i<=n;i++){
        max_=max(max_,f[i]);
    }
    cout << max_;
    return 0;
}
