#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a1,a2,b1,b2,d1,d2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    a1=(c1[0]-'0')*10+(c1[1]-'0');
    a2=(c2[0]-'0')*10+(c2[1]-'0');
    b1=(s1[0]-'0')*10+(s1[1]-'0');
    b2=(s2[0]-'0')*10+(s2[1]-'0');
    d1=s1[2]-'A';
    d2=s2[2]-'A';
    if(a1==a2){
        cout<<1;
        if(b1==b2){
            cout<<1;
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
                cout<<1;
                if(d1+1==d2||d2+1==d1)cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
