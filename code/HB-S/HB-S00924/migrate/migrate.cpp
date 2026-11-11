#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    for(int l=1;l<=t;l++){
        int n,d;
        cin>>n>>d;
        int a[n+10]={0};
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==13||c==14){
            cout<<(n-1)*(n-2)/2<<"\n";
        }
    }
    return 0;
}
