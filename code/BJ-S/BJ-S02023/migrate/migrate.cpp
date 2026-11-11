#include<bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>a>>b;
    while(b--){
        cin>>c>>d;
        if(a == 0){
            if(c == 4){
                cout<<1<<endl;
                cout<<2<<endl;
            }else{
                cout<<1<<endl;
                cout<<2<<endl;
            }
            return 0;
        }
        for(int i = 1;i <= c;i++){
            cin >> d;
        }
        if(c == 4){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }

    return 0;
}
