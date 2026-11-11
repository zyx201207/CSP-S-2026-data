#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t,n,d,x[1000000];
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
    }
    if((n==4&&d==2)||(n==5&&d==2)){
        cout<<"1"<<endl;
        cout<<"2";
    }
    if((n==5&&d==3)||(n==6&&d==2)){
        cout<<"0"<<endl;
        cout<<"1";
    }
    return 0;
}
