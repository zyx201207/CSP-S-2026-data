#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N],diff[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,p;
    cin>>c>>p;
    while(p--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            diff[i]=a[i]-a[i-1];
        }
        bool f=1;
        for(int i=2;i<=n;i++){
            if(diff[i]!=diff[i-1])f=0;
        }
        if(f){
            int k=diff[2];
            if(k>=d)cout<<0;
            else{
                cout<<n%d<<endl;
            }
        }else cout<<n%d<<endl;
    }
    return 0;
}
