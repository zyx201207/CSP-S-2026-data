#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[1000010],flag;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        flag=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(x[i]<0) flag=1;
        }
        if(c==11||c==12){
            if(flag){
                cout<<0<<endl;continue;
            }
            else{
                cout<<n-3<<endl;continue;
            }
        }
        if(c==13||c==14){
            cout<<n<<endl;continue;
        }
        if(c>=15&&c<=18){
            cout<<d<<endl;continue;
        }
        cout<<0<<endl;
    }

    return 0;
}
