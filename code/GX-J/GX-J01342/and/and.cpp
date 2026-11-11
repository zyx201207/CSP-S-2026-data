#include <bits/stdc++.h>
//i need 20pts, for only m=1,2,n
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,a[200005];
    int mx=0;
    int res=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;++i){
            if(a[i]>=mx)mx=a[i];
        }
    }
    else if(m==2){
        for(int i=1;i<=n-1;++i){
            for(int j=i+1;j<=n;++j){
                if(a[i]&a[j]>=mx)mx=a[i]&a[j];

            }
        }
    }
    else if(m==n){
            mx=a[1];
        for(int i=2;i<=n;++i){
            mx=mx&a[i];
        }
    }
    cout<<mx;
    return 0;
}

