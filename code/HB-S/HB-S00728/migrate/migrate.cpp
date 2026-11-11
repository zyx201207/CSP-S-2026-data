#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<n;
    }
    return 0;
}
