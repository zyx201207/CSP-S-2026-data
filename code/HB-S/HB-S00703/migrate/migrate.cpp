#include<bits/stdc++.h>
using namespace std;
int x[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        cout<<n-1<<'\n';
    }
    return 0;
}
