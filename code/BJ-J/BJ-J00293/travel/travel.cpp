#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
    }
    else{
        cout<<"1";
        int l1=(s1[0]-'0')*10+(s1[1]-'0');
        int l2=(s2[0]-'0')*10+(s2[1]-'0');
        if(l1!=l2){
            cout<<"000";
        }
        else{
            cout<<"1";
            int a=s1[2]-'A';
            int b=s2[2]-'A';
            if( (a<=2&&b<=2)||(a>2&&b>2) ){
                cout<<"1";
                if(a-b==1||b-a==1){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
    }
    return 0;
}