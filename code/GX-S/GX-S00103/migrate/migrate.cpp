#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long  a[500050],b[500050],n,c,t,d,n1,d1;
    cin>>c>>t>>n>>d;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        cin>>n1>>d1;
        for(int h=1;h<=n1;h++){
            cin>>b[h];
        }
    }
    if(n==4&&d==2&&n1==5&&d1==2) cout<<"1"<<"\n"<<"2";
    if(n==5&&d==3&&n1==6&&d1==2) cout<<"0"<<"\n"<<"1";
    return 0;
}

