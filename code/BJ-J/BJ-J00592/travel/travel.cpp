#include<bits/stdc++.h>
using namespace std;
long long c1,c2;
string s1,s2;
long long h1,h2,l1,l2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    h1=(s1[0]-48)*10+(s1[1]-48);
    h2=(s1[0]-48)*10+(s2[1]-48);
    if(s1[2]=='A')
        l1=1;
    if(s1[2]=='B')
        l1=2;
    if(s1[2]=='C')
        l1=3;
    if(s1[2]=='D')
        l1=4;
    if(s1[2]=='E')
        l1=5;
    if(s2[2]=='A')
        l2=1;
    if(s2[2]=='B')
        l2=2;
    if(s2[2]=='C')
        l2=3;
    if(s1[2]=='D')
        l2=4;
    if(s1[2]=='E')
        l2=5;
    if(c1==c2){
        cout<<1;
        if(h1==h2){
            cout<<1;
            if((l1<=3&&l2<=3)||(l1>3&&l2>3)){
                cout<<1;
                if(abs(l1-l2)==1){
                    cout<<1;
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else
        cout<<"0000";
    return 0;
}
