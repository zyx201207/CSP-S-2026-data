#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    int n,x[200002],d,c,t,l[200001];
    cin>>c>>t;
    for(int z=1;z<=t;z++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            l[i]=x[i]-x[i-1];
        }
    }
    return 0;
}
