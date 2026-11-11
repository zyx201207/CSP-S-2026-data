#include<bits/stdc++.h>
using namespace std;
int c,t,n,a[200001],delta,d;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            delta=a[2]-a[1];
            if(2*delta<=d&&3*delta>=d){
                cout<<n-3<<'\n';
            }
            else{
                cout<<0<<'\n';
            }
        }
    }//18:06 8pts
    
}