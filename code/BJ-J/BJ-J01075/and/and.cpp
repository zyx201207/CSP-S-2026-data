#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,maxn;
bool f = 1;
bool two(long long x){
    while(x!=1){
        if(x%2==1) return 0;
        x/=2;
    }
    return 1;
}
int main(){
    freeopen("and.in","r",stdin);
    freeopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        cin>>a[i];
        maxn = max(maxn,a[i]);
        long long x = a[i]+1;
        if(!two(x)) f = 0;
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==2){
        for(int i = 1;i<=n;++i){
            for(int j = i+1;j<=n;++j){
                ans = max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        ans = a[1];
        for(int i = 2;i<=n;++i){
            ans &= a[i];
        }
        cout<<ans;
        return 0;
    }
    if(f){
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i = n;i>=1;--i){
        if(a[i]%2==0){
            cout<<a[i];
            return 0;
        }
    }
    cout<<1;
    return 0;
}
