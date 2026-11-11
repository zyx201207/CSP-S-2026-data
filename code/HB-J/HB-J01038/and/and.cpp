#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[20000005];
int ma=INT_MIN;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m;i++){
        int o=a[i];
        for(int j=1;j<=m;j++){
            o=o&&a[j];
        }
        ma=max(o,ma);
    }
    cout<<ma;
    return 0;
}
