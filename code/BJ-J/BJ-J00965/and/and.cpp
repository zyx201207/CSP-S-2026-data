#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
int maxl=INT_MIN;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            maxl=max(maxl,a[i]);
        }
        cout<<maxl;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                maxl=max(maxl,(a[i]&a[j]));
            }
        }
        cout<<maxl;
        return 0;
    }
    if(m==n){
        int x=2147483647;
        for(int i=1;i<=n;i++){
            x&=a[i];
        }
        cout<<x;
        return 0;
    }
    if(m==n-1){
        for(int i=1;i<=n;i++){
            int x=2147483647;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                x=x&a[j];
            }
            maxl=max(maxl,x);
        }
        cout<<maxl;
        return 0;
    }
    return 0;
}
