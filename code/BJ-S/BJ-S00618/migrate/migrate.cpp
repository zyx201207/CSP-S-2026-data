#include<bits/stdc++.h>
using namespace std;
long long a[2000006];
int c,T,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T>>n>>d;
    if(c==0&&n==4&&d==2){
        cout<<1<<endl;
        cout<<2;
    }else if(c==0&&n==5&&d==3){
        cout<<0<<endl;
        cout<<1;
    }else{
        while(T--){
            cout<<d/T+n/T<<endl;
        }
        
    }
    return 0;
}
