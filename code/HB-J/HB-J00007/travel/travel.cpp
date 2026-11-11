#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1;
    cin>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }else {
        cout<<"1";
        int a=s1[0]*10+s1[1];
        int b=s2[0]*10+s2[1];
        char C,D;
        C=s1[2];
        D=s2[2];
        if(a==b){
           cout<<"1";
            if((C=='A'||C=='B'||C=='C')&&(D=='A'||D=='B'||D=='C')){
                cout<<"1";
            }else if((C=='D'||C=='F')&&(D=='D'||D=='F')){
                cout<<"1";
            }else {
                cout<<"0";
            }
            if((C=='A'&&D=='B')||(D=='A'&&C=='B')||(C=='B'&&D=='C')||(D=='B'&&C=='C')||(C=='D'&&D=='F')||(D=='D'&&C=='F')){
                cout<<"1";
            }else {
                cout<<"0";
            }
        }else {
            cout<<"000";
        }


    }
    return 0;
}
