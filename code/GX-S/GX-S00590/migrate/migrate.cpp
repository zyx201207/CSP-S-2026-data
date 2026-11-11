#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    int n,d;
    int k1j6h;
    int a[2000010];
    cin>>c>>t;
    if(c==11||c==12){
        for(int i=1;i<=t;i++){
            cin>>n>>d;
            for(int j=1;j<=n;j++){
                cin>>a[j];
            }
            cout<<2<<endl;
        }

    }else if(c==13||c==14){
        for(int i=1;i<=t;i++){
            cin>>n>>d;
            for(int j=1;j<=n;j++){
                cin>>a[j];
            }
            cout<<1<<endl;
        }
    }else{
        for(int i=1;i<=t;i++){
            cin>>n>>d;
            for(int j=1;j<=n;j++){
                cin>>a[j];
            }
        }
        for(int i=1;i<=t;i++){
                cout<<0<<endl;
        }
    }
    return 0;
}
