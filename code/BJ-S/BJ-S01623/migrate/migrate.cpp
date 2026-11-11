#include<bits/stdc++.h>
using namespace std;
long long n,d,x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i = 1;i <= n;i++){
            cin>>x[i];
        }
        int a = x[2]-x[1];
        int b = d/a;
        if(b>1){
            if(n<b){
                cout<<(b-n)/2;
            }
        }else{
            cout<<0;
            return 0;
        }
    }
    return 0;
}
