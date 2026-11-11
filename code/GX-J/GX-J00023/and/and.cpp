#include <bits/stdc++.h>
using namespace std;
int sum[0];
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;
    int m;
    int tmp;
    int gog=0;
    cin>>n>>m>>tmp;
    for(int i=0;i<=n;i++){
        cin>>sum[i];
        gog=max(sum[i],sum[i-1]);
    }
    cout<<gog;

    return 0;
}
