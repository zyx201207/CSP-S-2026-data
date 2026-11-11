#include <bits/stdc++.h>
using namespace std;

longlong a[1e30];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n>>m;
    for(int i=0;i<n;i++){
        int >> a[i];
    }
    int sum=0,ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,sum);
        for(int f=0;f<m;f++){
            sum=(a[(i+f)%n] and sum);
        }
    }
    cout << ans;
    return 0;
}
