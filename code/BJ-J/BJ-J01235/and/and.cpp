#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[M],ans=0,s;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        for(int l=i+1;l<=n;l++){
            s=a[i]&a[l];
            ans=max(s,ans);
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
