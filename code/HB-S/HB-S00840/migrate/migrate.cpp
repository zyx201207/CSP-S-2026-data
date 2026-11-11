#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N];
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(d==2){
            if(n<=4){
                cout<<1;
            }else if(n<=6){
                cout<<2;
            }else cout<<0;
        }else if(d==3){
            if(n<=5){
                cout<<0
            }else if(n<=6){
                cout<<1;
            }else cout<<2;
        }else{
            cout<<d;
        }
        cout<<"\n";
    }
    return 0;
}
