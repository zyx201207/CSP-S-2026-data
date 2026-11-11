#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int ans;
int main(){
    freopen("and3.in","r",stdin);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans, a[i]&a[j]);
            }
        }
    }
    if(m==1){
        sort(a+1, a+n+1,greater<int>());
        ans=a[1];
    }
    if(m==n){
        ans=a[1];
        for(int i=1;i<=n;i++){
            ans&=a[i];
        }
    }
    if(m==n-1){
        sort(a+1, a+n+1,greater<int>());
        ans=a[1];
        for(int i=1;i<=n-1;i++){
            ans&=a[i];
        }
    }
    cout << ans;
    return 0;
}