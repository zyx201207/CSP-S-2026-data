#include <bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;



int main()
{
    freopen("travel.in","/home/noilinux/travel",stdin);
    freopen("travel.out","/home/noilinux/travel",stdout);
    cin>>c1>>c2>>c3>>c4;

    if(c1[1]==c3[1]&&c1[2]==c3[2]){
            cout<<1;
    }else{
            cout<<"0000";
            return 0;
    }


    if(c2[1]==c4[1]&&c2[2]==c4[2]){
            cout<<1;
    }else{
            cout<<"000";
            return 0;
    }




    if(c2[3]<='C'&&c4[3]<='C'){
            cout<<1;
    }else if(c2[3]<='F'&&c4[3]<='F'){
            cout<<1;
    }else{
            cout<<"00";
            return 0;
    }



    if(c2[3]!='F'&&c2[3]!='D') {
        char c6d=max(c2[3],c4[3]),c6x=min(c2[3],c4[3]);
        if(c6d-c6x==1){
            cout<<1;
        }
    }else if((c2[3]=='F'&&c4[3]=='D')||(c2[3]=='D'&&c4[3]=='F')){
        cout<<1;
    }else{
            cout<<"0";
            return 0;
    }
    return 0;
}
