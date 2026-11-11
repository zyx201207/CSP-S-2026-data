#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[999999],l=0;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
        l=max(l,a[i]);
    }
    return 0;
}
