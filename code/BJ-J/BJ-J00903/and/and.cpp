#include<bits/stdc++.h>
using namespace std;
int n,m,a[351599],ans = -1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    if (m == 1){
        sort (a+1,a+n+1);
        cout<<a[n];
    }else if (m == 2){
        for (int i=1;i<n;i++){
            for (int j=i+1;j<=n;j++){
                ans = max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }else if (m == n){
        ans = a[1];
        for (int i = 2;i<=n;i++){
            ans = ans & a[i];
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
