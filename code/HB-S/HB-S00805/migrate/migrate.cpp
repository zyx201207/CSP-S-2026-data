#include<bits/stdc++.h>
using namespace std;
int x[10005];
void dj(){
    int n ,d;
    cin>>n>>d;
    int ans=0;
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++){
        if(x[i+3]!=0) ans++;
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        dj();
    }
    return 0;
}
