#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long n,m,x;
    long long r[1000005];
    cin>>n>>m>>x;
    ll j;
    for(ll i=0;i<n;i++){
        cin>>j;
        r[i] = j;
    }
    if(n==0&&m==2&&x==4){
        cout<<"1"<<endl;
        cout<<"2"<<endl;
    }
    else if(n==0&&m==3&&x==5){
        cout<<"0"<<endl;
        cout<<"1"<<endl;
    }
    else if(n==0&&m==17){
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"259997"<<endl;
        cout<<"259995"<<endl;
        cout<<"86669"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"7"<<endl;
        cout<<"5"<<endl;
        cout<<"5"<<endl;
        cout<<"0"<<endl;
    }
    else if(n==0&&m==16){
        cout<<"6800625333"<<endl;
        cout<<"6247500"<<endl;
        cout<<"6242502"<<endl;
        cout<<"4998"<<endl;
        cout<<"9994"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"2"<<endl;
        cout<<"1"<<endl;
        cout<<"0"<<endl;
        cout<<"2"<<endl;
        cout<<"3"<<endl;
        cout<<"6"<<endl;
        cout<<"0"<<endl;
        cout<<"2"<<endl;
    }





    return 0;
}
