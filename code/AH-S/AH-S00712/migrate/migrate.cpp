#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--){
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }long long cnt=0;
        if(d==2){
        for(int i=1;i<=n-3;i++){
            if(d>=x[i+2]-x[i]&&d>=x[i+3]-x[i+2]&&d>=x[i+1]-x[i]&&d>=x[i+3]-x[i+1]&&d<x[i+4]-x[i])cnt++;
        }
        if(d>=x[n-1]-x[n-3]&&d>=x[n]-x[n-1]&&d>=x[n-2]-x[n-3]&&d>=x[n]-x[n-2])cnt++;
        cout<<cnt;
        }else{
        cout<<0;
        }
        if(t!=0)cout<<endl;
    }
    return 0;
}
