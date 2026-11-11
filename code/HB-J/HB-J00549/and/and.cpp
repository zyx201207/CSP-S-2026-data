#include <bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int n,m,a[maxn],ans,x;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(m==2){
        for (int i=1;i<n;i++){
            for (int j=i+1;j<=n;j++){
                x=a[i]&a[j];
                ans=max(x,ans);
            }
        }
    }
    else if (m==1){
        for (int i=1;i<=n;i++){
            x=a[i]&a[i];
            ans=max(x,ans);
        }
    }
    else if (m==n){
        ans=a[1];
        for (int i=2;i<=n;i++){
            ans=ans&a[i];
        }
    }
    else{
        ans=a[n];
    }
    cout << ans;
    return 0;
}
