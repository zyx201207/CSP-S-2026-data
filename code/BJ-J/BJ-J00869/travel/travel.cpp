#include <bits/stdc++.h>
using namespace std;
int main(){
    string a ,b ,c, d,line1,line2;
    char q ,w;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<'1';
    }else{
        cout<<"0000";
        return 0;
    }
    line1+=b[0];
    line1+=b[1];
    line2+=d[0];
    line2+=d[1];
    if(line1==line2){
        cout<<'1';
    }else{
        cout<<"000";
        return 0;
    }
    q=b[2];
    w=d[2];
    if((q=='A'||q=='B'||q=='C')&&(w=='A'||w=='B'||w=='C')){

            cout<<'1';
    }else if((q>='D'&&q<='F'&&q!='E')&&(w>='D'&&w<='F'&&w!='E')){

            cout<<'1';
    }
    else{
        cout<<"00";
        return 0;
    }

    if(q-w==1||q-w==-1){
            cout<<'1';
    }
    else if((q=='D'&&w=='F')||(w=='D'&&q=='F')){

            cout<<'1';

    }else{
        cout<<'0';
    }
    return 0;

}
