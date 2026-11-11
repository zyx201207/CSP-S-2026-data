#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[2010];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1) cout<<a[n];
    else cout<<a[n-1];
    return 0;
}
