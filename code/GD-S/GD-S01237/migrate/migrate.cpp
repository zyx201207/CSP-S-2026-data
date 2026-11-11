#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+10;
int a[maxn];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(d<(a[2]-a[1])*2){
            cout<<"0\n";
            continue;
        }else{
            cout<<n-(d/(a[2]-a[1])+2)+1<<"\n";
        }
    }
    return 0;
}