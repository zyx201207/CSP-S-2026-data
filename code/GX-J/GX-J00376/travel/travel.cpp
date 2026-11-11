#include <bits/stdc++.h>
using namespace std;

int main(){
    string a[10];
    string b[10];
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<=2;i++){
        cin>>a[i];
    }
    for(int i=0;i<=2;i++){
        cin>>b[i];
    }
    for(int i=0;i<=5;i++){
        if(a[i]==b[i]) cout<<"1";
        else cout<<"0";
    }
    return 0;
}
