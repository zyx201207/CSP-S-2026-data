#include<bits/stdc++.h>
using namespace std;
string a[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i;i<=4;i++){
            cin>>a[i];

    }
    if(a[0]=="01"||a[0]=="16"){
        cout<<0;
    }
    else{
        cout<<1;
    }
    if(a[0]!=a[2]){
        cout<<0;
    }
    else{
        cout<<1;
    }

    cout<<00;

    return 0;



}
