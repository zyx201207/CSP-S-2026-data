#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,a,m[100005];
    cin>>n>>a;
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }
    cout<<m[n];
    return 0;
}
