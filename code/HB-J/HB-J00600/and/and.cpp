#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[1000];
    for(int i=1; i<=n; i++){
            cin>>a[i];


    }
    int s=0;
    for(int i=1; i<=n-m; i++){
        for(int j=1; j<=n; i++){
            max(s,a[i]/a[j]);
        }

    }
    return 0;
}
