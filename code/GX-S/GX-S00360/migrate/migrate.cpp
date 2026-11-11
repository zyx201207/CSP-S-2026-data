#include<bits/stdc++.h>
using namespace std;
int x[10000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    int n,d;
    cin>>c>>t;
    cin>>n>>d;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
    }
    return 0;
}
