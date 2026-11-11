#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int t=1;t<=n;t++){
        int l=t;
        for(int i=t;i<=n;i++){
            if(a[i]==a[t]) l=i;
        }
        for(int i=l;i<=n;i++){
            ans[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
