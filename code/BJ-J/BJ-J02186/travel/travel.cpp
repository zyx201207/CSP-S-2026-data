#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int aa=(a[0]-'0')*10+a[1]-'0';
    int bb=(b[0]-'0')*10+b[1]-'0';
    int cc=(c[0]-'0')*10+c[1]-'0';
    int dd=(d[0]-'0')*10+d[1]-'0';
    if(aa==cc)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(bb==dd)cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if((d[2]-b[2]==1||b[2]-d[2]==1)&&(d[2]!='C'||b[2]!='D')&&(d[2]!='D'||b[2]!='C')){
        cout<<11;
    }
    else if(b[2]=='A'){
        if(d[2]=='C'){
            cout<<10;
        }
        else cout<<"00";
    }
    else if(b[2]=='C'){
        if(d[2]=='A'){
            cout<<10;
        }
        else cout<<"00";
    }else{
        cout<<"00";
    }
    return 0;
}
