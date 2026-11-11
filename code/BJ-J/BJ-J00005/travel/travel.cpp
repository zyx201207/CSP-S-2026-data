#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int x=b[0]*10+b[1],y=d[0]*10+d[1];
    if(a==c)
        cout<<1;
    else {
        cout<<"0000";
        return 0;
    }
    if(x==y)
        cout<<1;
    else {
        cout<<"000";
        return 0;
    }
    int b2=b[2]-'A'+1,d2=d[2]-'A'+1;
    if(b2<=3&&d2<=3){
        if(abs(b2-d2)==1)
            cout<<"11";
        else cout<<"10";
    }
    else if(b2>=4&&d2>=4)
            cout<<"11";
    else
        cout<<"00";

    return 0;
}
