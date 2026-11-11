#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a=0;
    cin>>n>>m;
    string x;
    x[1000];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        a=max(x[0]^m,x[i-1]^m);
    }
    cout<<a;
    return 0;
}
