#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if (a==c&&a!="01"&&a!="16"&&c!="01"&&c!="16"){
        cout<<"1";
        if (b[1]==d[1]) cout<<"1";
        else{
            cout<<"000";
            return 0;
        }
        if ((('A'<=b[2]<='C'&&'A'<=d[2]<='C')||('D'<=b[2]<='F'&&'D'<=d[2]<='F'))&&b[2]!='E'&&d[2]!='E') cout<<"1";
        else{
            cout<<"00";
            return 0;
        }
        if ('A'<=b[2]<='C'&&'A'<=d[2]<='C'){
            if (b[2]+1==d[2]||b[2]-1==d[2])cout<<"1";return 0;
            else cout<<"0";return 0;
        }else if(('D'<=b[2]<='F'&&'D'<=d[2]<='F'))&&b[2]!='E'&&d[2]!='E'){
            if (b[2]+2==d[2]||b[2]-2==d[2])cout<<"1";return 0;
            else cout<<"0";return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
