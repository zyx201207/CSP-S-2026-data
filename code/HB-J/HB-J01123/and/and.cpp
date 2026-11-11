#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.out","r",stdin);
    freopen("and.in","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[10000];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<a[n];
    return 0;
}
