#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    int p1,p2;
    int ce1,ce2;
    cin>>c1>>s1>>c2>>s2;
    p1=s1[0]+s1[1];
    p2=s1[0]+s2[1];
    if(s1[2]>='A'&&s1[2]<='C'){
        ce1=1;
    }
    else
        ce1=2;

    if(s2[2]>='A'&&s2[2]<='C'){
        ce2=1;
    }
    else
        ce2=2;

    if(c1==c2){
        cout<<'1';
        if(p1==p2){
            cout<<'1';
            if(ce1==ce2){
                cout<<'1';
                if(ce1==2&&ce2==2 || s1[2]=='A'&& s2[2]=='B' || s1[2]=='B'&&s2[2]=='C'){
                    cout<<'1';
                }
                else
                    cout<<'0';
            }
            else
                cout <<"00";
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";
    return 0;
}
