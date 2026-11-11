#include<bits/stdc++.h>
using namespace std;

int x[2000005];

void solve(){
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n;i++) cin>>x[i];
    cout<<(x[n-1]-d+1)/d<<endl;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++) solve();
    return 0;
}
