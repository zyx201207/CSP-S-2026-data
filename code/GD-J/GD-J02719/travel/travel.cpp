#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int l=b[2]-'A';
    int r=d[2]-'A';
    if (!(a[0]==c[0]&&a[1]==c[1])){
        cout<<"0000";
        return 0;
    }
    if (!(b[0]==d[0]&&b[1]==d[1])){
        cout<<"1000";
        return 0;
    }
    if (!((l<3&&r<3)||(l>=3&&r>=3))){
        cout<<"1100";
        return 0;
    }
    if (max(l,r)-min(l,r)==1){
        cout<<"1111";
        return 0;
    }else{
        cout<<"1110";
    }
    return 0;
}

