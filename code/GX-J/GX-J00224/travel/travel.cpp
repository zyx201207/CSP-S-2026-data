#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
char a[1234],b[1234],c[1234],d[1234];
cin>>a[1]>>a[2];
cin>>b[1]>>b[2]>>b[3];
cin>>c[1]>>c[2];
cin>>d[1]>>d[2]>>d[3];
if(a[1]==c[1]&&a[2]==c[2]){
    cout<<'1';
    if(b[1]==d[1]&&b[2]==d[2]){
        cout<<'1';
        if(d[3]-'A'<3&&b[3]-'A'<3||d[3]-'A'>3&&b[3]-'A'>3){
            cout<<'1';
            if(d[3]-'A'>3&&b[3]-'A'>3||d[3]-b[3]==1||d[3]-b[3]==1){
                cout<<'1';
            }
            else{
                cout<<'0';
            }
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else{
        cout<<"000";
        return 0;
    }
}
else{
    cout<<"0000";
    return 0;
}
return 0;
}
